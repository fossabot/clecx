#ifndef A7EA9678_D42C_4254_B218_B76A24A3E309
#define A7EA9678_D42C_4254_B218_B76A24A3E309

class NodeVisitor
{

};

struct ASTNode {
    virtual void accept(NodeVisitor& visitor) = 0;
};

#endif /* A7EA9678_D42C_4254_B218_B76A24A3E309 */
