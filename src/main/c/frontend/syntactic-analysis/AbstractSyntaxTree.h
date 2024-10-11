#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include <stdlib.h>

#include "../../shared/Logger.h"

/** Initialize module's internal state. */
void initializeAbstractSyntaxTreeModule();

/** Shutdown module's internal state. */
void shutdownAbstractSyntaxTreeModule();

/**
 * This typedefs allows self-referencing types.
 */

typedef enum ProgramType ProgramType;
typedef enum WorldExpressionsType WorldExpressionsType;
typedef enum MainExpressionsType MainExpressionsType;
typedef enum MainExpressionType MainExpressionType;

typedef struct ID ID;

typedef struct Program Program;

typedef struct ProgramExpression ProgramExpression;
typedef struct MainExpressions MainExpressions;
typedef struct WorldExpression WorldExpression;

typedef struct MainExpression MainExpression;
typedef struct WorldExpressions WorldExpressions;

typedef struct TreeExpression TreeExpression;
typedef struct ForestExpression ForestExpression;
typedef struct ForExpression ForExpression;
typedef struct ConditionalExpression ConditionalExpression;
typedef struct Assignment Assignment;
typedef struct ArithmeticExpression ArithmeticExpression;
typedef struct GrowExpression GrowExpression;
typedef struct Attributes Attributes;

/**
 * Node types for the Abstract Syntax Tree (AST).
 */

/*
	Enums for the ast
*/
enum ProgramType { WORLDLESS, WORLD };

enum WorldExpressionsType { ASSIGNMENT, WORLD_EXPRESSIONS };

enum AssignmentExpressionsType {UNIQUE, MULTIPLE};

enum AssignmentValues {INTEGER, BOOLEAN, STRING, HEXCOLOR};

enum ConditionalExpressionType {IF, ELSE_IF};

enum ConditionalClauseExpressionType {VALUE, EXPRESSION};

enum ConditionalClauseExpressionsType {LESSER, GREATER, EQUAL, LESSER_EQUAL, GREATER_EQUAL, NOT_EQUAL};

enum MainExpressionsType { MAIN_EXPRESSION, MAIN_EXPRESSIONS };

enum MainExpressionType { TREE, FOREST, FOR, ASSIGNMENT, CONDITIONAL, ARITHMETIC };

/* 
	Structs for the ast
*/

struct ID{
	Id idValue;
};


struct MainExpression {
    ID *id;
};

struct WorldExpression {
	WorldExpressions *worldExpressions;
};


struct ProgramExpression {
    union {
        MainExpression *mainExpression;
        struct {
            WorldExpression *worldExpression;
            MainExpression *mainExpression;
        };
    };
	ProgramType type;
};

struct Program {
    ProgramExpression *programExpression;
};

/**
 * Node recursive destructors.
 */
void releaseID(ID *ID);
void releaseProgram(Program *program);
void releaseProgramExpression(ProgramExpression *programExpression);
void releaseWorldExpression(WorldExpression *worldExpression);
void releaseWorldExpressions(WorldExpressions *worldExpressions);
void releaseMainExpression(MainExpression *mainExpression);
void releaseMainExpressions(MainExpressions *mainExpressions);
void releaseTreeExpression(TreeExpression *treeExpression);

#endif
