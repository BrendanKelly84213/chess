#include <iostream>

#include "PlayerView.h"

int main( int argc, char *argv[] )
{

    std::string initial_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    std::string random_fen = "5b2/4p1P1/7p/7q/3k1K2/2p1p1P1/b4Prr/2n1B3 w - - 0 1";
    std::string castle_fen = "rnbqkbnr/pp1pp1pp/2p5/4Pp2/2B5/5N2/PPPP1PPP/RNBQK2R w KQkq - 0 1";
    std::string buggy_fen = "2r3k1/1q1nbppp/r3p3/3pP3/pPpP4/P1Q2N2/2RN1PPP/2R4K b - b3 0 23";
    std::string test_special_ep_fen = "8/6bb/8/8/R1pP2k1/4P3/P7/K7 b - d3 0 0";
    std::string kiwipete = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - ";
    std::string in_check = "rnb1kbnr/pppppppp/8/8/1q6/3P4/PPP1PPPP/RNBQKBNR w - - 0 1";
    std::string pos3 = "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - ";
    std::string pos4 = "r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1";
    std::string weird_queen = "4K3/8/1q6/8/8/7Q/8/2k5 b - - 0 1";
    std::string en_passant_next_turn = "rnbqkbnr/pppppppp/8/6P1/8/8/PPPPPP1P/RNBQKBNR b KQkq - 0 1";

    // std::string jams = "1k5r/pbp3p1/1p3q2/2b1nB2/4PP2/3P4/PPP3PP/R1BQ1RK1 w - - 1 16";
    std::string jams = "1kb3q1/p1p5/1p6/n2P1P2/3QP1pr/6RB/PPP3PP/1R5K w - - 2 31";
    std::string jams2 = "3r2k1/p4pp1/7p/4P3/3NQ3/2q5/PrP1KPPP/R6R w - - 3 23";


    Colour player_side = White;
    if(argv[1]) {
        if(strcmp(argv[1], "white") == 0)
            player_side = White;
        else if(strcmp(argv[1], "black") == 0)
            player_side = Black;
        else 
            printf("Player side not Known. defaulting to white. %s", argv[1]);
    } 

    bool board_inverted = false;
    if(argv[2] != NULL && strcmp(argv[2], "invert") == 0)
        board_inverted = true;


    PlayerView game;

    printf("Playing as %s!\n", colour_to_str(player_side).c_str());

    game.init(initial_fen, player_side, board_inverted);
            
    game.run();

    return 0;
}
