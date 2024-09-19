/**


evaluate("((4-(7-6))*8)") => 24

evaluate("(((6-7)+4)*8)") => ERROR
evaluate("(6/((8-7)/4))") => ERROR


split("((3*5)+4)") => ( "(3*5)", '+', "4" )
split("7")         => None


*/

int calculater(string expression){
  if (!split(expression)){

    return stoi(expression);
  }

  auto [firstexp, operator, secondexp] = split(expression);

  int first = calculater(firstexp);
  int second = calculater(secondexp);

  if (first < 0 || second < 0) return -1;

  if (operator == '+') return first + second;
  else if (operator == '-') {
    if (first <= second) return -1;
    return first - second;
  }
  else if (operator == '/') {
    if (first % second != 0) return -1;
    return first / second;
  }
  else return first * second;
}


/*

inputs: [1, 2, 3, 4]
target: 24


Some (not all) solutions:
"((1*2)*(3*4))"
"((3+1)*(4+2))"

*/

"((1+2)+4)"
"(1+(2+4))"

"1+2+4+8+9"
"1" '+' "2+4+8+9"
"2" "+" "4+8+9"

"8 + 9" "(8+9)"

"(1+2)+4"
"((1+2)+4)"


"1+4+2"



string solve(int[] inputs, int target) {
  for (perm : permutations(inputs)){
    vector<string> cur_exprs;
    for (int i = 0; i < perm.length(); ++i){
      for (auto op : "+-*/"){
        for (auto x : cur_exprs): // 4 * cur_exp
          cur_expr2 = cur_expr + op + perm[i];
          cur_exprs2.push_back(cur_expr)
      }

      else {
        cur_exp = perm[i];
      }
      cur_exprs = cur_exprs2;
    }

    for (string expression : cur_exprs){
      if (calculator(expression) == target){
        return expression;
      }
    }
  }
}

string gen_all_expressions(string inputs){
  int count_operators = inputs.count("+", "-", "/", "*");
  if (count_operators == 1 || !count_operators){
    return "(" + inputs + ")";
  }

  auto pivot = inputs.find("+", "-", "/", "*");
  string first = inputs.substr(inputs.begin(), pivot - 1);
  string second = inputs.substr(pivot + 1, inputs.end());

  string firstpart = gen_all_expressions(first);
  string secondpart = gen_all_expressions(second);

  return "(" + first + pivot + second + ")";
}
