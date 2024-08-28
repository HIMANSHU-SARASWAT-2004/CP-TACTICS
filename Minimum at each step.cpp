vi minimum_at_each_step(vi v){
    int n = v.size();
    reverse(all(v));
    vi ans;
    int mn = v[0];
    ans.pb(mn);
    repeat(i,1,n){
        mn = min(mn, v[i]);
        ans.pb(mn);
    }
    reverse(all(ans));
    return ans;
}
