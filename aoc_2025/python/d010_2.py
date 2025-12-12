# AI-Assisted Solution
import re
import sys
from z3 import Optimize, Int,  sat, Sum

def solve_machine(line):
    target_match = re.search(r'\{([\d,]+)\}', line)
    if not target_match:
        return 0
    targets = [int(x) for x in target_match.group(1).split(',')]
    num_counters = len(targets)
    
    clean_line = re.sub(r'\[.*?\]', '', line)
    button_matches = re.findall(r'\(([\d,]+)\)', clean_line)
    
    buttons = []
    for b in button_matches:
        affected_indices = [int(x) for x in b.split(',')]
        buttons.append(affected_indices)
        
    opt = Optimize()
    
    presses = [Int(f'b_{i}') for i in range(len(buttons))]
    
    for p in presses:
        opt.add(p >= 0)
        
    for i in range(num_counters):
        expr = Sum([presses[j] for j, btn_indices in enumerate(buttons) if i in btn_indices])
        opt.add(expr == targets[i])
        
    total_presses = Sum(presses)
    opt.minimize(total_presses)
    
    if opt.check() == sat:
        model = opt.model()
        return model.eval(total_presses).as_long()
    else:
        print(f"No solution found for: {line}")
        return 0

def main():
    input_data = sys.stdin.read().strip().split('\n')
    
    total_presses = 0
    
    for line in input_data:
        if not line.strip(): continue
        result = solve_machine(line)
        total_presses += result
        
    print(f"\nans: {total_presses}")

if __name__ == "__main__":
    main()
