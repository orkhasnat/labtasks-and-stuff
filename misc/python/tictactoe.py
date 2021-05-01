# player1=input('Where do you want to place your X');
# player2=input('Where do you want to place your O');


def player_marker_choice():
    print("Player1 please choose X or O")
    while True:
        player1_marker = input().upper()
        if player1_marker != "X" and player1_marker != "O":
            print("PLease choose a valid input")
        else:
            if player1_marker == "X":
                return ("X", "O")
            else:
                return ("O", "x")


def draw():
    # print("\n" * 10)
    print(board[7] + "|" + board[8] + "|" + board[9])
    print("-|-|-")
    print(board[4] + "|" + board[5] + "|" + board[6])
    print("-|-|-")
    print(board[1] + "|" + board[2] + "|" + board[3])


def place_marker(marker):
    inp="Which position do you like to choose "
    while True: 
        position=int(input(inp+f"({marker})?\n"))
        if board[position] != " ":
            print("Please choose a valid position.")
            continue
        else:
            board[position] = marker
            break


def win_check(marker):
    if board[1] == marker and board[2] == marker and board[3] == marker:
        # could have also written board[1]==board[2]==board[3]==marker
        return True
    if board[1] == board[4] == board[7] == marker:
        return True
    if board[1] == marker and board[5] == marker and board[9] == marker:
        return True
    if board[4] == marker and board[5] == marker and board[6] == marker:
        return True
    if board[7] == marker and board[8] == marker and board[9] == marker:
        return True
    if board[2] == marker and board[5] == marker and board[8] == marker:
        return True
    if board[3] == marker and board[6] == marker and board[9] == marker:
        return True
    if board[3] == marker and board[5] == marker and board[7] == marker:
        return True
    else:
        return False


def player_choice():
    position = 0
    while not space_check(position):
        position = int(input("Choose a position\n"))
    return position


def replay():
    print("Do you want to play again?")
    yes = input("Press Y to play again.Else press N.\n").upper()
    return yes == "Y"


def tie_check():
    if " " in board[1:]:
        return False
    else:
        return True

p1,p2 =player_marker_choice()

while True:
    board=['0','1','2','3','4','5','6','7','8','9']
    draw()
    board=[" "]*10
    while True:
        place_marker(p1)
        print("\n" * 10)
        draw()
        if win_check(p1):
            print(f"Congrats Player1 {p1} you win")
            break
        if tie_check():
            print("Game Tied.")
            break
        place_marker(p2)
        print("\n" * 10)
        draw()
        if win_check(p2):
            print(f"Congrats Player2 {p2} you win")
            break
    if replay():
        continue
    else:
        input("Press any key to exit")
        exit()


    