# ����ͷ���

* maintype��1�ֽڣ�������������
* subtype��1�ֽڣ�����������͵�����
* length��2�ֽڣ������ĵ��ܳ���
* msg ���Ϊ2048�ֽڣ����ĵ���Ϣ���ɸ��ݲ�ͬ�ı���������ת��



# �������

## **client��¼**
��Ϊ|maintype|subtype|
---|:--:|---:
�����¼|0x11(login)|0x00(request)
��¼�ɹ���֪ͨserver��|0x11(login)|0x01(success)
�״θ���|0x11(login)|0x02(changepwd)

</br>

#### ������Ϣ(�����¼)

* 32λ�û���
* 32λ����

#### ������Ϣ(��¼�ɹ�)

* ��

#### ������Ϣ(�״θ���)


* 32λ����

## **client����ѷ����ı�**

#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
�����ı���Ϣ|0x14(sndTxt)| x(��������Ϣ�û�������)

#### ������Ϣ

* x �� 32�ֽڵ�char�� �����߻����ߵ��û��� name1 name2 name3 ...��
* �Ϊ MAXLENGTH ������

#### ע��
���ΪȺ����Ϣ����xΪ0��������Ϣֱ��Ϊ���͵�����

</br>

## **client���������޸ĺ����б���Ϣ**

#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
֪ͨ����|0x22(updateList)| 0x01(tellOnline)
֪ͨ����|0x22(updateList)| 0x00(tellOffline)

#### ������Ϣ

* 32�ֽڵ�char�� �����߻����ߵ��û�����

</br>


## **client����������Ϣ**

#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
��������|0x21(conf)| 0x01(winTheme)
������ʷ����|0x21(conf)| 0x03(hisNum)
����������ɫ|0x21(conf)| 0x04 (fontColor)
���������С|0x21(conf)| 0x05 (fontSize)
#### ������Ϣ���������塢��ʷ���ȡ���ɫ�������С��

* 4�ֽ�����



## **client����ѷ����ļ�**
### �׶�1��������Ϣͷ���ģ��õ��ļ�id�ͷֳɶ��ٸ�����������׶���ɴ��ļ�ָ�룬����id���ļ�ָ��Ĺ�ϵ��������idΪͨ��md5ɢ�еõ���16�ֽڵ�ֵ

#### ����ͷ  �������߸������ߣ�

��Ϊ|maintype|subtype|
---|:--:|:---:
�����ļ�|0x12(sndFileHead)|0x01(file)
����jpg|0x12(sndFileHead)|0x02(jpg)
����gif|0x12(sndFileHead)|0x03(gif)

#### ��������
* 32�ֽڵ�char�� ���û����� // ����Ϊ�����ߵ��û������հ�Ϊ�����ߵ��û�����server��������
* 32�ֽڵ�char�� ���ļ�����
* 16�ֽ����� id �������ļ���ţ�
* int���� count ������һ����������

#### ����ͷ  �������߻ظ������ߣ�
��Ϊ|maintype|subtype|
---|:--:|:---:
ѡ�����|0x73(resFileHead)|0x01(success)
�ܾ�����|0x73(resFileHead)|0x00(failed)

#### ��������
* 16�ֽ��ļ�id

### �׶�2���������ݰ����ͷְ�֮�������


#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
�����ļ�������Ϣ|0x13(sndFile)|0x00(filedata)

#### ��������
* 32�ֽ�char���ͣ��������û����� //
* 16�ֽ� id �������ļ���ţ� // ��ͨ���û����ж�
* int���� count ������ڼ�������
* �Ϊ MAXLENGTH ������

### �׶�3�������ļ����������־ ��֪ͨ�����ļ�������

#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
�����ļ�������Ϣ|0x13(sndFile)|0x01(success)

#### ��������
* 16�ֽ� id �������ļ���ţ�

## **server��Ӧ��¼**

��Ϊ|maintype|subtype|
---|:--:|:---:
��֤ʧ��|0x71(resLogin)|0x00(failed)
��֤�ɹ�|0x71(resLogin)|0x01(success)
�״ε�¼��ǿ�Ƹ��ܣ�|0x71(resLogin)|0x02(changepwd)
�������|0x71(resLogin)|0x03(pwderror)
�ظ���¼��ǿ�����ߣ�|0x71(resLogin)|0x04(repeatoff)
�ظ���¼�������ߣ�|0x71(resLogin)|0x05(repeaton)
#### ��������
* ��


## **server��client����������Ϣ**
#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
��������|0x81(resConf)|0x01(winTheme)
�����б�|0x81(resConf)|0x02(friList)
��ʷ����|0x81(resConf)| 0x03(hisNum)
#### ��������
* 4�ֽ�����

## **server��Ӧת��״̬**

#### ����ͷ  

��Ϊ|maintype|subtype|
---|:--:|:---:
�ɹ�ת��|0x72(resSend)|0x01(success)
�������Ʋ�����|0x72(resSend)|0xfe(idNotExit)
����δ����|0x72(resSend)|0xfd(idOffline)
����ת��|0x72(resSend)|0x07(offlineSnd)

#### ��������
* char name[32] ���������ƣ�

# ����ʵ��


```
namespace cstate 
{
	const char online = '1' ;
	const char offline = '0' ;
};

 namespace mt
 {
	 // client  send 
	const unsigned char login = 0x11;
	const unsigned char sndFileHead = 0x12 ;
	const unsigned char sndFile = 0x13;
	const unsigned char sndTxt = 0X14;

	const unsigned char conf = 0x21 ;
	const unsigned char updateList = 0x22 ;

	const unsigned char resLogin = 0x71;
	const unsigned char resSend = 0X72;
	const unsigned char resConf = 0X81 ;
	const unsigned char resFileHead =0x73;
 };

namespace sbt
{
	const unsigned char myDefault = 0x00 ;

	const unsigned char request = 0x00 ;
	const unsigned char success = 0x01 ;
	const unsigned char changepwd = 0x02 ;

	const unsigned char groupChat = 0x00 ;
	const unsigned char file = 0x01;
	const unsigned char jpg = 0x02;
	const unsigned char gif = 0x03 ;

	const unsigned char failed = 0x00;
	const unsigned char pwderror = 0x03 ;
	const unsigned char repeatoff = 0x04 ;
	const unsigned char repeaton = 0x05 ;
	const unsigned char pwdChangeErr = 0x06;

	const unsigned char idNotExit = 0xfe;
	const unsigned char idOffline = 0xfd;

	const unsigned char winTheme = 0x01;
	const unsigned char friList = 0x02 ;
	const unsigned char hisNum = 0x03 ;
	const unsigned char fontColor = 0x04 ;
	const unsigned char fontSize = 0x05;
	const unsigned char hisMsg = 0x06 ;

	const unsigned char tellOnline = 0x01 ;
	const unsigned char tellOffline = 0x02 ;
	const unsigned char offlineSnd = 0x07 ;

};




struct packetHeader{
	unsigned char mainType ;
	unsigned char subType ;
	unsigned short length;
};

struct TxtData
{
	char friName [MAXNAMELEN ];
	char txtMsg [MAXDATALEN];
};

//  �����ļ����͵����� ����һ�����������ʽ  
struct fileHeader 
{
	char friName [MAXNAMELEN]; 
	char fileName [MAXNAMELEN];
	int  fileId ;
	int  packNum ;
};

//  file ����
struct fileData{
	char friName[MAXNAMELEN];
	int fileId ;
	int count ;
	char data[MAXDATALEN];
};


//  ��֤��¼
struct loginData{
	char username [MAXNAMELEN];
	char passwd [MAXPASSWDLEN];
};

struct changePwdData {
	char newPasswd [MAXPASSWDLEN];
};

```




