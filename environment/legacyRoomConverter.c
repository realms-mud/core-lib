//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

protected string *dest_dir;
protected mapping exits;
protected string short_desc = "";
protected string long_desc = "";
protected string *items;
protected mixed property;
protected int no_castle_flag;
protected string long_exit, short_exit;
protected mapping clone_list = ([]);
protected int alwaysLight;

/////////////////////////////////////////////////////////////////////////////
public void set_short(string arg)
{
    short_desc = arg;
}

/////////////////////////////////////////////////////////////////////////////
public void set_long(string arg)
{
    long_desc = arg;
}

/////////////////////////////////////////////////////////////////////////////
public void set_light(int arg)
{
    alwaysLight = arg;
}

/////////////////////////////////////////////////////////////////////////////
public void set_dest_dir(string *arg)
{
    dest_dir = arg;
}

/////////////////////////////////////////////////////////////////////////////
public void set_items(string *arg)
{
    items = arg;
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
}

/////////////////////////////////////////////////////////////////////////////
protected object clone_object(string objectFile)
{
    clone_list[objectFile] = 1;
    return efun::clone_object(objectFile);
}

/////////////////////////////////////////////////////////////////////////////
public void add_clone(string file, int quantity)
{
    clone_list[file] = quantity;
}

/////////////////////////////////////////////////////////////////////////////
public void add_wanderer(string file, int quantity)
{
    clone_list[file] = quantity;
}

/////////////////////////////////////////////////////////////////////////////
private string translateFile(string oldFile)
{
    if (oldFile[0] != '/')
    {
        oldFile = "/" + oldFile;
    }
    return regreplace(oldFile, "players", "lib\/legacy");
}

/////////////////////////////////////////////////////////////////////////////
private string annotateAuthor(string inputFile)
{
    string ret = inputFile;
    string fileName = object_name(this_object());
    
    if (sizeof(regexp(({ fileName }), "players\/[a-zA-Z]+")))
    {
        string wizardName = regreplace(fileName, ".*players\/([a-zA-Z]+)\/.*", "\\1");
        ret = regreplace(inputFile, "AUTHOR", capitalize(wizardName));
    }
    else
    {
        ret = regreplace(inputFile, "// Translated with permission, originally written by: AUTHOR @ RealmsMUD\n", "");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string generateShortDescription(string inputFile)
{
    return regreplace(inputFile, "##ShortDescription##", short_desc);
}

/////////////////////////////////////////////////////////////////////////////
private string generateLongDescription(string inputFile)
{
    string longDesc = regreplace(long_desc, "\n", "\\n\"\n        \"", 1);
    longDesc = regreplace(longDesc, "\"\n +\"+$", "", 1);
    return regreplace(inputFile, "##LongDescription##", longDesc);
}

/////////////////////////////////////////////////////////////////////////////
private string generateExits(string inputFile)
{
    string exitList = "";
    int totalExitEntries = sizeof(dest_dir);
    for (int i = 0; i < totalExitEntries; i += 2)
    {
        exitList += sprintf("    addExit(\"%s\", \"%s\");\n",
            dest_dir[i + 1], translateFile(dest_dir[i]));
    }

    if (sizeof(exitList))
    {
        exitList += "\n";
    }
    return regreplace(inputFile, "[/][*] AddExits [*][/]\n", exitList);
}

/////////////////////////////////////////////////////////////////////////////
private string generateLightMethod(string inputFile)
{
    string light = "";
    if (alwaysLight)
    {
        light = "\n/////////////////////////////////////////////////////////////////////////////\n"
            "protected int alwaysLight()\n{\n    return 1;\n}\n\n";
    }
    return regreplace(inputFile, "[/][*] IsLight [*][/]\n", light);
}

/////////////////////////////////////////////////////////////////////////////
private string generateObjects(string inputFile)
{
    string objectList = "";
    if (sizeof(clone_list))
    {
        foreach(string element in clone_list)
        {
            int numCopies = clone_list[element];
            for (int i = 0; i < numCopies; i++)
            {
                objectList += sprintf("    addObject(\"%s\");\n", 
                    translateFile(element));
            }
        }
    }

    return regreplace(inputFile, "[/][*] AddObjects [*][/]\n", objectList);
}

/////////////////////////////////////////////////////////////////////////////
private string generateItems(string inputFile)
{
    string itemList = "";
    int totalItemEntries = sizeof(items);
    for (int i = 0; i < totalItemEntries; i += 2)
    {
        itemList += sprintf("    addLegacyItem(\"%s\", \"%s\");\n",
            items[i], items[i+1]);
    }

    if (sizeof(itemList))
    {
        itemList += "\n";
    }
    return regreplace(inputFile, "[/][*] AddItems [*][/]\n", itemList);
}

/////////////////////////////////////////////////////////////////////////////
private string generateCustomMethods(string inputFile)
{
    string methods = "";

    return regreplace(inputFile, "[/][*] AddMethods [*][/]\n", methods);
}

/////////////////////////////////////////////////////////////////////////////
public string generateNewRoom()
{
    string newFile = read_file("/lib/environment/legacyRoomTemplate.c");

    newFile = annotateAuthor(newFile);
    newFile = generateShortDescription(newFile);
    newFile = generateLongDescription(newFile);
    newFile = generateExits(newFile);
    newFile = generateLightMethod(newFile);
    newFile = generateObjects(newFile);
    newFile = generateItems(newFile);
    newFile = generateCustomMethods(newFile);

    return newFile;
}
