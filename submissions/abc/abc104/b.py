S = input()
if S[0]!='A':
  print('WA')
else:
  i = 2
  count = 0
  while i < len(S)-1:
  	if S[i] == 'C':
      		count += 1
  	i += 1
  if count != 1:
    print('WA')
  else:
    S = S.replace('A','').replace('C','')
    if S.islower() == False:
      print('WA')
    else:
      print('AC')
