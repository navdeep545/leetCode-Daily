class SnapshotArray
{

    vector<unordered_map<int, int>> v;
    int snapid;

public:
    SnapshotArray(int length)
    {
        v.resize(length);
        snapid = 0;
    }

    void set(int index, int val)
    {
        v[index][snapid] = val;
    }

    int snap()
    {
        snapid++;
        return snapid - 1;
    }

    int get(int index, int snap_id)
    {
        // int x = -1;
        while (!v[index].count(snap_id) && snap_id >= 0)
        {
            snap_id--;
        }
        return v[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */