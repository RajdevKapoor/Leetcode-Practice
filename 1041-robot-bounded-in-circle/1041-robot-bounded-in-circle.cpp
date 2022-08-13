class Solution {
public:
    bool isRobotBounded(string s) {
        char curr_dir = 'N';
        int x = 0;
        int y = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'G') {
                if(curr_dir == 'N') {
                    y+=1;
                } else if(curr_dir == 'E') {
                    x+=1;
                } else if(curr_dir == 'S') {
                    y-=1;
                } else if(curr_dir == 'W') {
                    x-=1;
                }
            } else {
                char facing_dir = s[i];
                if(curr_dir == 'N') {
                    if(facing_dir == 'L') {
                        curr_dir = 'W';
                    } else {
                        curr_dir = 'E';
                    }
                } else if(curr_dir == 'E') {
                    if(facing_dir == 'L') {
                        curr_dir = 'N';
                    } else {
                        curr_dir = 'S';
                    }
                } else if(curr_dir == 'S') {
                    if(facing_dir == 'L') {
                        curr_dir = 'E';
                    } else {
                        curr_dir = 'W';
                    }
                } else if(curr_dir == 'W') {
                    if(facing_dir == 'L') {
                        curr_dir = 'S';
                    } else {
                        curr_dir = 'N';
                    }
                }
            }
        }

        if(x == 0 && y == 0 || curr_dir != 'N') {
            return true;
        }
        return false;
    }
};