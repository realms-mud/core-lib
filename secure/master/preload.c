//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
protected string initFile = "room/init_file";
protected int ShouldAutoLoadCoreLib = 1;

static int currentTime;

/////////////////////////////////////////////////////////////////////////////
private nomask varargs int executionTime(int previousTime)
{
    int *timeAsArray = rusage();
    currentTime = timeAsArray[0] + timeAsArray[1];

    return currentTime - previousTime;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string *traverseDirectoryForSourceFiles(string *baseDir)
{
    string *ret = ({});

    baseDir = filter(baseDir, (: !sizeof(regexp(({ $1 }), "tests")) :));

    foreach(string file in baseDir)
    {
        if ((sizeof(file) > 2) &&
            (file[(sizeof(file) - 2)..(sizeof(file) - 1)] == ".c"))
        {
            ret += ({ "/" + file });
        }
        else if (file_size(file) == -2)
        {
            ret += traverseDirectoryForSourceFiles(get_dir(file + "/", 0x10));
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *LoadCoreLib()
{
    string *ret = ({});
    if (ShouldAutoLoadCoreLib)
    {
        string *files = get_dir("/lib/", 0x10);
        ret += traverseDirectoryForSourceFiles(files);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *LoadInitFile(string initFile, string *exclusions)
{
    return filter(explode(read_file(initFile), "\n"),
        (: ((sizeof($1) > 1) && ($1[0] != '#') && (member($2, $1) < 0)) :), exclusions);
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *epilog(int eflag)
{
    executionTime();
    string *preloadFiles = ({});

    if (!eflag)
    {
        preloadFiles = LoadCoreLib();

        if (file_size(initFile) > 0)
        {
            preloadFiles += LoadInitFile(initFile, preloadFiles);
        }
    }
    return preloadFiles;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void preload(string file)
{

}
