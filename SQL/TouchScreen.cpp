enum TOUCH_EVENT { TOUCHDOWN = 0x81, RELEASE = 0x80 };
typedef struct _TouchContext
{
    TOUCH_EVENT event;
    int x_coord;
    int y_coord;
} TouchContext;
#define PACKET_SIZE 5
#define BUFFER_SIZE 100
#define CONTEXT_SIZE BUFFER_SIZE / PACKET_SIZE
#define PACKET_SIZE 5
#define BUFFER_SIZE 100
#define CONTEXT_SIZE BUFFER_SIZE / PACKET_SIZE

class TouchScreen
{
public:
    unsigned char m_buffer[BUFFER_SIZE + PACKET_SIZE];
    int m_buff_size;

    TouchScreen()
    {
        memset(m_buffer, 0, sizeof(m_buffer));
        m_buff_size = 0;
    };
    /* This is your down stream call you, we expect capacity in number of context*/
    int read_touch_context(TouchContext* context_buff, int capacity)
    {
        TouchContext touch_context;
        int count = 0;
        for (int i = 0; i < m_buff_size; i++)
        {
            if (m_buff_size - i < PACKET_SIZE)
            {
                memcpy(&m_buffer[0], &m_buffer[i], m_buff_size - i);
                m_buff_size = m_buff_size - i;
                break;
            }
            else if (m_buffer[i] != TOUCHDOWN && m_buffer[i] != RELEASE)
            {
                /* ignore garbage*/
                continue;
            }
            else
            {
                touch_context.event = (TOUCH_EVENT)m_buffer[i];
                touch_context.x_coord = m_buffer[i + 1] * 256 + m_buffer[i + 2];
                touch_context.y_coord = m_buffer[i + 3] * 256 + m_buffer[i + 4];
                i += 4;
                context_buff[count] = touch_context;
                count++;
                /* we read more than customer wanted*/
                if (count == capacity)
                {
                    if (m_buff_size - i > 0)
                    {
                        memcpy(&m_buffer[0], &m_buffer[i], m_buff_size - i);
                        m_buff_size = m_buff_size - i;
                    }
                    break;
                }
            }
        }
        return count;
    }

    /* This function is use for read stream from RS232, can also be used for unit test*/
    void read_stream(unsigned char * buffer, int size)
    {
        /* Do not feed me more than I can accetpt*/
        if (size > BUFFER_SIZE - m_buff_size)
        {
            size = BUFFER_SIZE - m_buff_size;
        }
        memcpy(&m_buffer[m_buff_size], buffer, size);
        m_buff_size += size;
    }
};

void TestTouchScreen(void)
{
    Logger::WriteMessage("Test TouchScreen");
    vector<vector<unsigned char>> streams =
    {
        {0x81, 0x08, 0x16, 0x07, 0x41, 0x90, 0x80, 0x08, 0x16, 0x07},
        {0x41, 0x90, 0x81, 0x01, 0x2, 0x01, 0x02}
    };
    TouchContext context_buff[50];
    TouchScreen touchStreen;
    for (size_t i = 0; i < streams.size(); i++)
    {
        touchStreen.read_stream((unsigned char *)&streams[i][0], streams[i].size());
        int count = touchStreen.read_touch_context(context_buff, 10);
        printf("Count = %d\n", count);
        for (int j = 0; j < count; j++)
        {
            printf("TouchContext {event = %d, x_coord = %d, y_coord = %d}\n", 
                context_buff[j].event, context_buff[j].x_coord, context_buff[j].y_coord);
        }
    }
}