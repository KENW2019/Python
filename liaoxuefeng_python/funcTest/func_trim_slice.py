
def trim(Lstr_input):
    Lint_len = len(Lstr_input)

    Lint_startIndex = 0
    Lint_endIndex = Lint_len-1

    while Lint_startIndex < Lint_len:
        if Lstr_input[Lint_startIndex] != " ":
            break
        Lint_startIndex += 1

    if Lint_startIndex >= Lint_len:
        print("string is all spece")
        return ""

    while Lint_endIndex > Lint_startIndex:
        if Lstr_input[Lint_endIndex] != " ":
            break
        Lint_endIndex -= 1

    return Lstr_input[Lint_startIndex:Lint_endIndex+1]
