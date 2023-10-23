  struct ListNodex {
      string val;
      ListNodex *next;
      ListNodex *prev;
      ListNodex(string x) : val(x), next(nullptr), prev(nullptr) {}
  };

class BrowserHistory {
public:
    ListNodex* current = nullptr;

    BrowserHistory(string homepage) {
        current = new ListNodex(homepage);
    }
    
    void visit(string url) {
        ListNodex* new_page = new ListNodex(url);
        new_page -> prev = current;

        current->next = new_page;
        current = current->next;
    }
    
    string back(int steps) {
        
        while(steps && current->prev!= nullptr){
            current = current->prev;
            steps--;
        }
        return current->val;

    }
    
    string forward(int steps) {
        while(steps && current->next != nullptr){
            current = current->next;
            steps--;
        }
        return current->val;
    }
};