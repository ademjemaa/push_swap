# push_swap
sorting stacks for 42

copy paste for testing :

ARG=\`ruby -e "puts (0..3).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker -v $ARG 

ARG=\`ruby -e "puts (0..5).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker -v $ARG

ARG=\`ruby -e "puts (0..100).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker -v $ARG

ARG=\`ruby -e "puts (0..500).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker -v $ARG


length of stack and number of operations on average :
  3 == 5 (max 5)
  
  5 == 11 (max 12)
  
  100 == 833 (max 900)
  
  500 == 7900 (max 8500)
  
