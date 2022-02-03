#ifndef _DISKOBJECT_H_
#define _DISKOBJECT_H_

#define EF_ONLY_FILENAMES	0
#define EF_FULLY_QUALIFIED	1

 
//===========================================================================
// Summary:
//      To use a CDiskObject object, just call the constructor.
//      Disk Object
//===========================================================================

class CDiskObject 
{
public:
	// ctor(s)
	
	//-----------------------------------------------------------------------
	// Summary:
	// Disk Object, Constructs a CDiskObject object.
	//		Returns A  value.
	CDiskObject();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Disk Object, Constructs a CDiskObject object.
	//		Returns A  value.  
	// Parameters:
	//		feedbackWindow---Window, A pointer to the CWnd or NULL if the call failed.
	CDiskObject( CWnd* feedbackWindow );

	// dtor
	
	//-----------------------------------------------------------------------
	// Summary:
	// C Disk Object, Destructor of class CDiskObject
	//		Returns A  value.
	~CDiskObject();

	// - - -
	// Operations

	// Files

	
	//-----------------------------------------------------------------------
	// Summary:
	// File Exists, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		file---Specifies A CString type value.
	BOOL FileExists( const CString& file );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Create File, You construct a CDiskObject object in two steps. First call the constructor, then call Create, which creates the object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		file---Specifies A CString type value.
	BOOL CreateFile( const CString& file );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy File, Create a duplicate copy of this object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceFile---File, Specifies A CString type value.  
	//		destDirectory---Directory, Specifies A CString type value.
	BOOL CopyFile( const CString& sourceFile, const CString& destDirectory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove File, Call this function to remove a specify value from the specify object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceFile---File, Specifies A CString type value.
	BOOL RemoveFile( const CString& sourceFile );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy Files, Create a duplicate copy of this object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		destDirectory---Directory, Specifies A CString type value.
	BOOL CopyFiles( const CString& sourceDirectory, const CString& destDirectory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy Files, Create a duplicate copy of this object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		files---Specifies A CString type value.  
	//		destDirectory---Directory, Specifies A CString type value.
	BOOL CopyFiles( CStringArray& files, const CString& destDirectory );

	// Directories

	
	//-----------------------------------------------------------------------
	// Summary:
	// Create Directory, You construct a CDiskObject object in two steps. First call the constructor, then call Create, which creates the object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		directory---Specifies A CString type value.
	BOOL CreateDirectory( const CString& directory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy Directory, Create a duplicate copy of this object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		destDirectory---Directory, Specifies A CString type value.
	BOOL CopyDirectory( const CString& sourceDirectory, const CString& destDirectory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Empty Directory, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		directory---Specifies A CString type value.
	BOOL EmptyDirectory( const CString& directory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove Directory, Call this function to remove a specify value from the specify object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		directory---Specifies A CString type value.
	BOOL RemoveDirectory( const CString& directory );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Copy Directories, Create a duplicate copy of this object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		destDirectory---Directory, Specifies A CString type value.
	BOOL CopyDirectories( const CString& sourceDirectory, const CString& destDirectory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Empty Directories, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		directory---Specifies A CString type value.
	BOOL EmptyDirectories( const CString& directory );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Remove Directories, Call this function to remove a specify value from the specify object.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		directory---Specifies A CString type value.
	BOOL RemoveDirectories( const CString& directory );

	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum Files In Directory With Filter, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		filter---Specifies A CString type value.  
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		files---Specifies A CString type value.  
	//		mode---Specifies A integer value.
	BOOL EnumFilesInDirectoryWithFilter( const CString& filter, const CString& sourceDirectory, CStringArray& files, int mode = EF_ONLY_FILENAMES );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum All Directories, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		directories---Specifies A CString type value.
	BOOL EnumAllDirectories( const CString& sourceDirectory, CStringArray& directories );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum Directories, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		directories---Specifies A CString type value.
	BOOL EnumDirectories( const CString& sourceDirectory, CStringArray& directories );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum Files In Directory, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		files---Specifies A CString type value.  
	//		mode---Specifies A integer value.
	BOOL EnumFilesInDirectory( const CString& sourceDirectory, CStringArray& files, int mode = EF_ONLY_FILENAMES );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum All Files, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		files---Specifies A CString type value.
	BOOL EnumAllFiles( const CString& sourceDirectory, CStringArray& files );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Enum All Files With Filter, None Description.
	//		Returns TRUE on success; FALSE otherwise.  
	// Parameters:
	//		filter---Specifies A CString type value.  
	//		sourceDirectory---Directory, Specifies A CString type value.  
	//		files---Specifies A CString type value.
	BOOL EnumAllFilesWithFilter( const CString& filter, const CString& sourceDirectory, CStringArray& files );

	// Error handling
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Error Message, Returns the specified value.
	//		Returns a CString type value.
	CString GetErrorMessage();	

private:
	// Error handling
 
	// Message, You can freely substitute CString objects for const char* and LPCTSTR function arguments.  
	CString m_errorMessage;

	
	//-----------------------------------------------------------------------
	// Summary:
	// Clear Error, Remove the specify data from the list.

	void	ClearError();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set Internal Error Message, Sets a specify value to current class CDiskObject

	void	SetInternalErrorMessage();
	
	//-----------------------------------------------------------------------
	// Summary:
	// Set System Error Message, Sets a specify value to current class CDiskObject
	// Parameters:
	//		error---Specifies A integer value.  
	//		elements---Specifies A CString type value.
	void	SetSystemErrorMessage( int error, const CString& elements = _T( "" ) );

	// Helpers

 
	// Window, The CWnd class provides the base functionality of all window classes in the Microsoft Foundation Class Library.  
	CWnd*	m_feedbackWindow;
	
	//-----------------------------------------------------------------------
	// Summary:
	// Qualify Path, None Description.
	// Parameters:
	//		str---Specifies A CString type value.
	void	QualifyPath( CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Qualify File, None Description.
	// Parameters:
	//		str---Specifies A CString type value.
	void	QualifyFile( CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get File Name, Returns the specified value.
	//		Returns a CString type value.  
	// Parameters:
	//		str---Specifies A CString type value.
	CString GetFileName( const CString& str );
	
	//-----------------------------------------------------------------------
	// Summary:
	// Get Directory Name, Returns the specified value.
	//		Returns a CString type value.  
	// Parameters:
	//		str---Specifies A CString type value.
	CString GetDirectoryName( const CString& str );

};

#endif // _DISKOBJECT_H_
