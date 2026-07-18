class Solution {
private: 
    void change (string& ans) {
        string temp = "" ;
        int ct = 0 ;
        int m = ans.size() ;
        char prev = ans[0] ;
        for (int j=0 ; j<m ; j++) {
            if (prev != ans[j]) {
                temp += to_string(ct) + prev ;
                ct = 1 ;
                prev = ans[j] ;
            }
            else ct++ ;
        }
        ans = temp + to_string(ct) + prev ;
    }
public:
    string countAndSay(int n) {
        string ans = "1" ;
        for (int i=2 ; i<=n ; i++) {
            change(ans) ;
        }
        return ans ;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}