/*
WAF to find a character with maximum occurrence.

I/P - abccccd
O/P - c

I/P - apple1231111
O/P - 1
*/
function maxCharacter(str){
  const charMap = {};
  let max = 0, maxChar = "";

  for(let char of str){
    charMap[char] = charMap[char] + 1 || 1;
  }

  for(let char in charMap){
    if(charMap[char] > max){
      max = charMap[char];
      maxChar = char;
    }
  }
  
  return maxChar;
}
