#ifndef __UIFILE_H__
#define __UIFILE_H__

#pragma once

namespace DuiLib {
	/////////////////////////////////////////////////////////////////////////////////////
	//

	class UILIB_API CUIFile
	{
	public:
		CUIFile();
		~CUIFile();

		LPBYTE GetData() const;
		DWORD  GetSize() const;
		void Empty();

		BOOL LoadFile(const STRINGorID &bitmap, LPCTSTR type=NULL, HINSTANCE instance=NULL);
		BOOL LoadFile(LPCTSTR pStrImage, LPCTSTR type=NULL, HINSTANCE instance=NULL);
		BOOL LoadFile(UINT nID, LPCTSTR type=NULL, HINSTANCE instance=NULL);

	private:
		LPBYTE m_pData; 
		DWORD m_dwSize;
	};

	class UILIB_API CUIFileFind
	{
	public:
		CUIFileFind();
		~CUIFileFind();

		BOOL FindFile(LPCTSTR lpFileName);
		BOOL FindNextFile();
		void FindClose();

		//��ȡ�ҵ����ļ������ƣ�������չ����
		CDuiString GetFileName();

		//��ȡ�ҵ����ļ�������·���� ����·�����ļ�������չ��
		CDuiString GetFilePath();

// 		//��ȡ�ҵ����ļ������ƣ�û�а�����չ����
// 		CDuiString GetFileTitleName();
// 
// 		//��ȡ�ҵ����ļ�����չ��
// 		CDuiString GetFileExtName();

		//ȷ���ҵ����ļ��������Ƿ�������� "." �� "..."����ָʾʵ������һ��Ŀ¼��
		BOOL IsDots();

		//ȷ���ҵ����ļ��Ƿ�ΪĿ¼
		BOOL IsDirectory();

	protected:
		void MakeFullPath(CDuiString& sPath);
	private:
		CDuiString m_strRoot;
		BOOL m_bFindInZip;

		HANDLE m_hFind;
		void* m_pFoundInfo;
		void* m_pNextInfo;

		HANDLE m_hZip;
		ZIPENTRY m_zipEntry;
		ZIPENTRY m_zipEntryNext;
		int m_nZipIndex;
	};

} // namespace DuiLib

#endif // __UIFILE_H__
