//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
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

private string *methodsToIgnore = ({ "__INIT", "add_clone", "add_wanderer", 
    "annotateAuthor", "clone_object", "generateCustomMethods", "generateExits", 
    "generateItems", "generateLightMethod", "generateLongDescription", 
    "generateNewRoom", "generateObjects", "generateShortDescription", 
    "set_dest_dir", "set_items", "set_light", "set_long", "set_short", 
    "translateFile", "reset", "long", "set_property"
});

private mapping methodsToReplace = ([
    "query_name": "Name",
    "query_real_name": "RealName",
    "query_objective": "Objective",
    "query_pronoun": "Pronoun",
    "query_possessive": "Possessive",
    "query_gender": "Gender",
    "query_gender_string": "Gender",
    "query_hp": "hitPoints",
    "query_sp": "spellPoints",
    "query_level": "effectiveLevel",
    "hit_player": "hit",
    "query_money": "Money",
    "add_money": "addMoney",
    "add_spell_points": "spellPoints",
    "heal_self": "hitPoints",
    "add_soaked": "addSoaked",
    "drink_soft": "Soaked",
    "set_title": "Title",
    "set_pretitle": "Pretitle",
    "query_title": "Title",
    "query_pretitle": "Pretitle",
]);

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
public void long(string arg)
{
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
public void set_property(mixed propertyToSet)
{
    property = propertyToSet;
}

/////////////////////////////////////////////////////////////////////////////
public void set_terrain(string terrain)
{
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
    if (oldFile[(sizeof(oldFile) - 2)..] != ".c")
    {
        oldFile += ".c";
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
        ret = regreplace(inputFile, "// Translated with permission, originally written by: AUTHOR @ RealmsMUD(\r)*\n", "");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string sanitizeString(string inputString)
{
    string ret = regreplace(inputString, "([&*$^])", "\\\\1", 1);
    ret = regreplace(ret, "\"", "'", 1);
    ret = regreplace(ret, "(\r)*\n", "\\n\"\n        \"", 1);
    ret = regreplace(ret, "\"\n +\"+$", "", 1);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string generateShortDescription(string inputFile)
{
    return regreplace(inputFile, "##ShortDescription##", sanitizeString(short_desc));
}

/////////////////////////////////////////////////////////////////////////////
private string generateLongDescription(string inputFile)
{
    return regreplace(inputFile, "##LongDescription##", sanitizeString(long_desc));
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

    return regreplace(inputFile, "// AddExits(\r)*\n", exitList);
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
    return regreplace(inputFile, "// IsLight(\r)*\n", light);
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

    return regreplace(inputFile, "// AddObjects(\r)*\n", objectList);
}

/////////////////////////////////////////////////////////////////////////////
private string generateItems(string inputFile)
{
    string itemList = "";
    int totalItemEntries = sizeof(items);
    for (int i = 0; i < totalItemEntries; i += 2)
    {
        if (pointerp(items[i]))
        {
            foreach(string item in items[i])
            {
                itemList += sprintf("    addLegacyItem(\"%s\", \"%s\");\n",
                    item, sanitizeString(items[i + 1]));
            }
        }
        else
        {
            itemList += sprintf("    addLegacyItem(\"%s\", \"%s\");\n",
                items[i], sanitizeString(items[i + 1]));
        }
    }

    if (sizeof(itemList))
    {
        itemList += "\n";
    }
    return regreplace(inputFile, "// AddItems(\r)*\n", itemList);
}

/////////////////////////////////////////////////////////////////////////////
private string replaceObjectMethods(string inputFile)
{
    string ret = inputFile;

    string *methods = m_indices(methodsToReplace);
    foreach(string method in methods)
    {
        if(method == "hit_player")
        {
            ret = regreplace(ret, "(hit_player.[^,]+), (DAMAGE|RESIST)_[A-Z_]+", "\\1", 1);
        }
        ret = regreplace(ret, method, methodsToReplace[method], 1);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private string generateCustomMethods(string inputFile)
{
    string methods = "";

    string *fileDetails = explode(read_file(
        sprintf("/%s.c", object_name(this_object()))), "\n");
    string functionRegExp = ".*(" + 
        implode(functionlist(this_object()) - methodsToIgnore, "|") + ")[^;]+$";

    mapping fileLocations = ([ "end": sizeof(fileDetails) ]);

    int fileSize = sizeof(fileDetails);
    for (int i = 0; i < fileSize; i++)
    {
        if (sizeof(regexp(({ fileDetails[i] }), functionRegExp)))
        {
            fileLocations[regreplace(fileDetails[i], functionRegExp, "\\1")] = i;
        }
    }
    if (sizeof(fileLocations))
    {
        string *functions = sort_array(m_indices(fileLocations),
            (: $3[$1] > $3[$2] :), fileLocations);

        string previousFunction = 0;
        string *addedFunctions = ({});
        foreach(string functionName in functions)
        {
            if (previousFunction)
            {
                addedFunctions += fileDetails[fileLocations[previousFunction]..(fileLocations[functionName] - 1)];
            }
            previousFunction = functionName;
        }

        if (sizeof(addedFunctions))
        {
            methods = "/////////////////////////////////////////////////////////////////////////////\n" + methods;
            methods += implode(addedFunctions, "\n");
        }
    }

    int i = 0;
    while (i < sizeof(fileDetails))
    {
        if (sizeof(regexp(({ fileDetails[i] }), "#include \"[^\"]+\.c\".*")))
        {
            string fileToAdd = regreplace(fileDetails[i], "#include \"([^\"]+\.c)\".*", "\\1");
            if (fileToAdd)
            {
                methods += "\n" + read_file(fileToAdd);
            }
        }
        i++;
    }

    methods = replaceObjectMethods(methods);
    methods = regreplace(methods, "\"\/*players\/", "\"/lib/legacy\/", 1);
    return regreplace(inputFile, "// AddMethods(\r)*\n", methods);
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

    return regreplace(newFile, "\r", "", 1);
}
