extern int m_initmap[][50];                                 //ȫ�ֵ�ͼ
class CMap
{
public:
    CMap()                                                  //�޲ι���,���õ�ͼ�߿�,1����߿�
    {
        for (int i = 1; i < 49; i++)
        {   
            m_initmap[i][1] = 1;     
            m_initmap[i][48] = 1;      
        }
        for (int i = 1; i < 49; i++)
        {
            m_initmap[1][i] = 1;  
            m_initmap[48][i] = 1;  
        }
    }

    void printInitmap();                                    //���Ƶ�ͼ

    int editorMap(int n, int isEdited, int isRead);         // 0����Ĭ�ϵ�ͼ��1���������ұ༭�ĵ�ͼ

    int traversePoint(int x, int y);                        // �Զ����ͼʱ�����ظ����
};

