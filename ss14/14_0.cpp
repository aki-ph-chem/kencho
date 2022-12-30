// 緩和
// 最小値が更新されたらtrue,更新されなかったらfalse

template<typename T>
bool chmin(T& a,T b) {
    if(a > b){
        a = b;
        return true;
    }
    else return false;
}
