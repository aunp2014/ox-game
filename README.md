This is OX Game.

version 0.1
- Display table e.g.
	- Blank
	  ...
	  ...
      ...
	- First 'x' place (0,0)
	  x..
      ...
      ...
	- Next 'o' place (1,1)
      x..
      .o.
	  ...

version 0.2
- Get input
    - validate input
    - validate location

version 0.2.1
	Problem read_pos behave badly, instead of scanf(x,y) directly
	read line as string and use sscanf() instead.

version 0.2.2
	Check location before place a new piece

version 0.3
	Check for winning condition

File-IO Branch
	This branch will use file I/O to communicate with user instead
	board status (table) will print to file 'output-board' and
	location for each player will be in 'input-x' and 'input-o'
	for player 'x' and 'o' respectively.

version 0.1
	create output-board first, and message will be in 'output-mesg'
