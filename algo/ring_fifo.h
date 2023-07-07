template<typename T>
class ring_fifo
{
public:
    ring_fifo(unsigned size)
    : m_rptr(0)
    , m_wptr(0)
    , m_wrap(false)
    , m_data(new T[size])
    {

    }

    ~ring_fifo()
    {
        delete m_data;
        m_data = nullptr;
    }

    bool full()
    {
        if (m_rptr != m_wptr)
            return false;
        if (m_wrap)
            return true;
        return false;
    }

    bool empty()
    {
        if (m_rptr != m_wptr)
            return false;
        if (m_wrap)
            return false;
        return true;
    }

    bool push(const T elem)
    {
        if (full())
            return false;
        m_data[m_wptr] = T;
        m_wptr += 1;
        if (m_wptr == m_size)
        {
            m_wptr -= m_size;
            m_wrap = !m_wrap;
        }
        return true;
    }

    T peek()
    {
        assert(!empty());
        return m_data[m_rptr];            
    }

    bool pop()
    {
        if (empty())
            return false;
        m_rptr += 1;
        if (m_rptr == m_size)
        {
            m_rptr -= m_size;
            m_wrap = !m_wrap;
        }
        return true;
    }

private:
    unsigned  m_size;
    unsigned  m_rptr;
    unsigned  m_wptr;
    bool      m_wrap;
    T*        m_data;
};
