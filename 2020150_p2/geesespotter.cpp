
#include <iostream>
#include "geesespotter_lib.h"


char * createBoard(std::size_t xdim, std::size_t ydim)
{

	char *new_board= new char[xdim*ydim];
	for(std::size_t l{0};l<xdim*ydim;l++)
	{
		new_board[l]=0;
	}
	return new_board;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim)
{
	int index {};
	for (int i{0};i<ydim;i++)
	{
		for(int j{0};j<xdim;j++)
		{
            if ((board[index]&markedBit())==markedBit())
			{
				std::cout <<'M';
			}
            else if((board[index]&hiddenBit())==hiddenBit())
			{
				std::cout<<'*';
			}
			else
			{
				std::cout<< board[index];
			}
			index++;
		}
		std::cout<<std::endl;
	}
	index=0;
}
void cleanBoard(char *board)
{
	delete[] board;
	board=nullptr;
}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim)
{
	for(int k{0};k<xdim*ydim;k++)
	{
		board[k]=board[k]|hiddenBit();
	}
}

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
	std::size_t loc{yloc*xdim+xloc};
    if((board[loc]&markedBit())==markedBit())
	{
		board[loc]=board[loc]-0x10;
	}
    else if((board[loc]&hiddenBit())==hiddenBit())
	{
		board[loc]=board[loc]+0x10;
	}
    else if((board[loc]&valueMask())==board[loc])
	{
		return 2;
	}
	else
	{
		return 0;
	}
    return board[loc];
}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim)
{
	for (int x{0};x<xdim;x++)
	{
		for(int y{0};y<ydim;y++)
		{
            // compute surroundings for certain cell
			int result{0};
			for(int s_x{x-1};s_x<x+1;s_x++)
			{
				for(int s_y{y-1};s_y<y+1;s_y++)
				{
					if (s_x>=0 && s_y>=0 && s_x < xdim && s_y < ydim)
					{
						if(board[s_x*s_y]==9)
						{
							result++;
                            std::cout << "test"<<result << std::endl;
						}
					}
				}
			}
			board[x*y]=result;
		}
	}
}

int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc)
{
	std::size_t location{yloc*xdim+xloc};
	if(board[location]&&hiddenBit()==hiddenBit())
	{
        if((board[location]&valueMask())==0)
			{
                for(int y{static_cast<int>(yloc-1)};y<=yloc+1;y++)
				{
                    for(int x{static_cast<int>(xloc-1)};x<=xloc+1;x++)
					{
						//check if still on the board
						if(x<xdim&&y<ydim&&x>=0&&y>=0)
						{
							if(board[y*xdim+x]&markedBit()==0)
							{
							//from the statement to reveal the space
							board[y*xdim+x]= board[y*xdim+x]&valueMask();
                                
							}
						}
					}
				}
			}
        else if((board[location]&valueMask())==9)
		{
			return 9;
		}
		else
		{
			board[location]=board[location]&valueMask();
		}
	}
	else if(board[location]&markedBit()==markedBit())
	{
		return 1;
	}
	else if(board[location]&valueMask()==board[location])
	{
		return 2;
	}
	else
	{
		return 0;
	}
    return 0;
}



bool isGameWon(char *board, std::size_t xdim, std::size_t ydim)
{
	bool is_bool{false};
	for(int k{0};k<xdim*ydim;k++)
	{
		if(board[k]&hiddenBit()==hiddenBit())
		{
			return false;
		}else if(board[k]&valueMask()==board[k])
		{
			is_bool=true;
		}
		else if(board[k]|markedBit()==board[k])
		{
			is_bool=true;
		}
	}
	return is_bool;
}



