#ifndef DBFILE_H
#define DBFILE_H

#include "TwoWayList.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"
#include "Comparison.h"
#include "ComparisonEngine.h"
#include "DBFileDefs.h"
#include "GenericDBFile.h"
#include "HeapDBFile.h"
#include "SortedDBFile.h"
#include "BPlusDBFile.h"



class DBFile {
 private:

  GenericDBFile * dbf;

  File f;
  Page curPage;
  off_t curPageIndex;

 public:
  DBFile ();

  int Create (char *fpath, fType file_type, void *startup);
  int Open (char *fpath);
  int Close ();

  void Load (Schema &myschema, char *loadpath);

  void MoveFirst ();
  void Add (Record &addme);
  int GetNext (Record &fetchme);
  int GetNext (Record &fetchme, CNF &cnf, Record &literal);

};
#endif
