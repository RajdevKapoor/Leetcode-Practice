class Solution {
public:
    string number(int num){
        if(num == 1){ return "One";}
        else if(num == 2){return "Two";}
        else if(num == 3){return "Three";}
        else if(num == 4){return "Four";}
        else if(num == 5){return "Five";}
        else if(num == 6){return "Six";}
        else if(num == 7){return "Seven";}
        else if(num == 8){return "Eight";}
        else if(num == 9){return "Nine";}
        else if(num == 10){ return "Ten";}
        else if(num == 11){ return "Eleven";}
        else if(num == 12){return "Twelve";}
        else if(num == 13){return "Thirteen";}
        else if(num == 14){return "Fourteen";}
        else if(num == 15){return "Fifteen";}
        else if(num == 16){return "Sixteen";}
        else if(num == 17){return "Seventeen";}
        else if(num == 18){return "Eighteen";}
        else if(num == 19){return "Nineteen";}
        else if(num == 20){return "Twenty";}
        else if(num == 30){return "Thirty";}
        else if(num == 40){return "Forty";}
        else if(num == 50){return "Fifty";}
        else if(num == 60){return "Sixty";}
        else if(num == 70){return "Seventy";}
        else if(num == 80){return "Eighty";}
        else if(num == 90){return "Ninety";}
        return "Zero";
    }
    string numberToWords(int num) {
        int billion=1000000000,million=1000000,thousand=1000,hundred=100,ten=10,one=1,temp=0;
        string result ;
        
        int start = 0;
        
        if(num == 0){ return number(num);}
        
        while(num >0){
            if(start == 1 ){ result += " "; }
                start = 1;
            if(num>=billion){
                temp= num/billion;
                num %= billion;
                
                result += numberToWords(temp);
                result += " ";
                result += "Billion";
            }else if(num>=million){
                temp= num/million;
                num %= million;
                
                result += numberToWords(temp);
                result += " ";
                result += "Million";
            }else if(num>=thousand){
                temp= num/thousand;
                num %= thousand;
                
                result += numberToWords(temp);
                result += " ";
                result += "Thousand";
            }else if(num>=hundred){
                temp= num/hundred;
                num %= hundred;
                
                result += number(temp);
                result += " ";
                result += "Hundred";
            }else if(num>=20){
                temp= (num/10)*10;
                num %= ten;
                
                result += number(temp);
            }else if(num>=one){
                temp= num/one;
                num %= one;
                
                result += number(temp);
            }
        }
        
        return result;
    }
};