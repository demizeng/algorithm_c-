//header file for sort algorithm implemented by c plus plus

#ifndef SORT_H
#define SORT_H

//Comparetype 是类型名，默认为std::less<T>，使用Comparetype()可实例化一个std::less<T>的对象
template<typename Iterator,typename Comparetype=std::less<typename std::iterator_traits<Iterator>::value_type>>
class heap_sort
{
    private:
        Iterator iter_head;
        std::size_t iter_size;

    protected:
        void heap(int node_idx, std::size_t heap_size, Comparetype compare=Comparetype())
        {
            int father_idx=node_idx;
            int left_idx=2*father_idx+1;
            int identify_idx=father_idx;
            for(; left_idx<heap_size; left_idx=2*father_idx+1)
            {
                if(compare(*(iter_head+left_idx),*(iter_head+father_idx))) identify_idx=left_idx;
                if ((left_idx+1)<heap_size && compare(*(iter_head+left_idx+1),*(iter_head+identify_idx))) identify_idx=left_idx+1;
                if(identify_idx == father_idx) break;
                typename std::iterator_traits<Iterator>::value_type tempvalue=*(iter_head+father_idx);
                *(iter_head+father_idx)=*(iter_head+identify_idx);
                *(iter_head+identify_idx)=tempvalue;
                father_idx=identify_idx;
            }
        }

    public:
        typedef typename std::iterator_traits<Iterator>::value_type T;
        /*para1:指向待排序迭代器
          para2:待排序元素个数
          para3:指定最大堆或最小堆，默认最小堆(降序)
        */
        void sort(const Iterator iter_sort, std::size_t size, Comparetype compare=Comparetype())
        {
            iter_head=iter_sort;
            iter_size=size;

            if (iter_size>1)
            {
                for(int iter_idx=(iter_size-1)/2;iter_idx>=0;iter_idx--) heap(iter_idx,iter_size,compare);
                for(int tail_idx=iter_size-1;tail_idx>0;tail_idx--)
                {
                    typename std::iterator_traits<Iterator>::value_type tempvalue=*(iter_head);
                    *(iter_head)=*(iter_head+tail_idx);
                    *(iter_head+tail_idx)=tempvalue;
                    heap(0,tail_idx,compare);
                }
            }
        }      
};

#endif