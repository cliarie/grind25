import csv

def fit_text_on_board(text, board_size=26):
    board = [["" for _ in range(board_size)] for _ in range(board_size)]
    row, col = 0, 0

    for char in text:
        if row >= board_size:
            break
        board[row][col] = char
        col += 1
        if col >= board_size:
            col = 0
            row += 1

    return board

def save_board_to_csv(board, filename="board.csv"):
    with open(filename, mode="w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)
        writer.writerows(board)

# Input text
text = (
    "well 😏 by all accounts 💸you must have intelligence 🤓 in the topmost 🔝 percentage 📈 to comprehend Ralph 👴 and Morgan 👦. "
    "The jokes 😆 are intensely 😵understated 🪫; if one were lacking 🫥 a sturdy 🪵 hold 🤝 of abstract 💭science 🧑‍🔬, many of the japes would fly 🪁🪂 "
    "above the standard audience’s cranium 😶‍🌫️. additionally ➕, there’s Ralph’s cynical viewpoint 🔭, which is adeptly interlaced 🪡🧵into his psyche 🤯- "
    "his internal tenets 📝 pull deeply 🎣 from 🔲🔲🔲🔲🔲🔲🔲🔲🔲 🔲🔲🔲🔲🔲 books 📚, as an example. Send this to 9️⃣other mystery hunt teams 👬. If you get none ❎back, it’s a shutout game. If you get 6️⃣back, you’re working for Wolf 🦊. If you get all 9️⃣back, you’re a man 👱of god ⛪ ⛩️ 🛕 🕍 🕌."
)

# Create board and save it as CSV
board = fit_text_on_board(text)
save_board_to_csv(board)

print("Board saved as 'board.csv'")
