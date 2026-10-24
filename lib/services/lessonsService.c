//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping catalogs = ([]);
private mapping lessonInstances = ([]);
private mapping lessonNames = ([]);

/////////////////////////////////////////////////////////////////////////////
public nomask string *lessonPaths(string treePath)
{
    if (!member(catalogs, treePath) ||
        !objectp(catalogs[treePath]["tree"]))
    {
        object tree = getService("research")->researchTree(treePath);
        if (!tree)
        {
            raise_error(sprintf("ERROR - lessonsService: Invalid research "
                "tree %s.\n", treePath));
        }
        catalogs[treePath] = ([
            "tree":tree,
            "paths":tree.getResearchPaths() - ({ tree.TreeRoot() })
        ]);
    }
    return catalogs[treePath]["paths"] + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask object lessonObject(string path)
{
    if (!member(lessonInstances, path) || !objectp(lessonInstances[path]))
    {
        object item = getService("research")->researchObject(path);
        if (!item)
        {
            raise_error(sprintf("ERROR - lessonsService: Invalid research "
                "lesson %s.\n", path));
        }
        lessonInstances[path] = item;
    }
    return lessonInstances[path];
}

/////////////////////////////////////////////////////////////////////////////
public nomask string lessonName(string path)
{
    if (!member(lessonNames, path) || !lessonNames[path]["item"])
    {
        object item = lessonObject(path);
        lessonNames[path] = ([
            "item":item,
            "name":item.query("name")
        ]);
    }
    return lessonNames[path]["name"];
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *matchingLessons(string *paths, string name)
{
    string *ret = ({});
    foreach(string path in paths)
    {
        if (lower_case(lessonName(path)) == lower_case(name))
        {
            ret += ({ path });
        }
    }
    return ret;
}
