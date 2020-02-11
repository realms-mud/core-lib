//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
protected string initFile = "init/init_file";
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
            ret += traverseDirectoryForSourceFiles(get_dir(file + "/*", 0x10) -
                ({ (file + "/."), (file + "/..") }));
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
        string *files = get_dir("/lib/*", 0x10) -
            ({ "lib/.", "lib/.." });

        ret += traverseDirectoryForSourceFiles(files);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *LoadInitFile(string initFile, string *exclusions)
{
    string initFileData = read_file(initFile) - "\r";
    return filter(explode(initFileData, "\n"),
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
    int previousTime = currentTime;

    debug_message(sprintf("Compiling file: %s", file), 0x5);
    object compiledFile = load_object(file);

    if (objectp(compiledFile) &&
        function_exists("executeTests", compiledFile) &&
        (file != "/lib/tests/framework/testFixture.c"))
    {
        catch (compiledFile->executeTests());
    }

    debug_message(sprintf(" -> built in %d ms.\n", 
        executionTime(previousTime)), 0x5);
}
