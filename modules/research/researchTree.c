//*****************************************************************************
// Class: researchTree
// File Name: researchTree.c
//
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/prerequisites.c";
#include "/lib/include/itemFormatters.h"

protected nosave string FieldDisplay = "[0;36m%-15s[0m : [0;33m%s[0m\n";
private string ResearchDictionary = "/lib/dictionaries/researchDictionary.c";

private string name;
private string description;
private string source;
private string treeRoot;

private mapping tree = ([
]);

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        name = "";
        description = "";
        treeRoot = 0;
        tree = ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask object researchDictionary()
{
    object ret = 0;
    if (file_size(ResearchDictionary) > -1)
    {
        ret = load_object(ResearchDictionary);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isMemberOfResearchTree(string element)
{
    return member(tree, element);
}

/////////////////////////////////////////////////////////////////////////////
public nomask object getResearchItem(string element)
{
    object ret = 0;

    object dictionary = researchDictionary();
    if (dictionary)
    {
        ret = dictionary->researchObject(element);
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string Name(string newName)
{
    if(newName && stringp(newName))
    {
        name = newName;
    }
    return name;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string Description(string newDescription)
{
    if(newDescription && stringp(newDescription))
    {
        description = newDescription;
    }
    return description;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string Source(string newSource)
{
    if (newSource && stringp(newSource))
    {
        source = newSource;
    }
    return source;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string TreeRoot(string newRoot)
{
    if(newRoot && stringp(newRoot) && member(tree, newRoot))
    {
        if(getResearchItem(newRoot))
        {
            treeRoot = newRoot;
        }
        else
        {
            raise_error("ERROR - researchTree: the tree root element must "
                "exist and be a valid research item.\n");
        }
    }
    return treeRoot;
} 

/////////////////////////////////////////////////////////////////////////////
public nomask int prerequisitesMetFor(string researchItem, object owner)
{
    int ret = 0;

    if(researchItem && stringp(researchItem) && owner && objectp(owner) &&
       function_exists("isResearched", owner) && member(tree, researchItem))
    {
        object research = getResearchItem(researchItem);
        ret = checkPrerequisites(owner) && research &&
            research->checkPrerequisites(owner);

        string *dependencies = tree[researchItem]["parents"];
        if(dependencies && pointerp(dependencies) && sizeof(dependencies))
        {
            foreach(string dependency in dependencies)
            {
                ret &&= owner->isResearched(dependency);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask varargs mapping getTreeNode(string element, object owner, 
    int addDetails)
{
    mapping ret = ([ ]);

    if(element && stringp(element) && member(tree, element) && 
        researchDictionary()->researchObject(element))
    {
        object researchItem = getResearchItem(element);
        if(!tree[element]["children"])
        {
            ret[researchItem] = addDetails ? ([]) : 0;
        }
        else if(pointerp(tree[element]["children"]) && 
                sizeof(tree[element]["children"]) &&
                stringp(tree[element]["children"][0]))
        {
            ret[researchItem] = ([ ]);
            foreach(string child in tree[element]["children"])
            {
                object childItem = getResearchItem(child);

                if (addDetails)
                {
                    ret += getTreeNode(child, owner, 1);
                }
                else
                {
                    ret[researchItem] += getTreeNode(child, owner);
                }
            }
        }

        if (addDetails && owner && objectp(owner))
        {
            if (owner->isResearched(element))
            {
                ret[researchItem] += (["researched":1]);
            }
            else if (owner->isResearching(element))
            {
                ret[researchItem] += (["researching":1]);
            }
            else if (prerequisitesMetFor(element, owner))
            {
                ret[researchItem] += (["can research":1]);
            }
        }
    }
    return ret + ([ ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getResearchTree(object owner)
{
    mapping ret = ([ ]);
    if(treeRoot && stringp(treeRoot))
    {
        ret += getTreeNode(treeRoot, owner);
    }
    return ret + ([ ]);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping getFlattenedResearchTree(object owner)
{
    mapping ret = ([]);
    if (treeRoot && stringp(treeRoot))
    {
        ret += getTreeNode(treeRoot, owner, 1);
    }
    return ret + ([]);
}

/////////////////////////////////////////////////////////////////////////////
private nomask int validateRelationship(string child, string parent)
{
    int ret = 1;
    if (member(tree, parent) && member(tree[parent], "parents") && tree[parent]["parents"] &&
        (member(tree[parent]["parents"], child) > -1))
    {
        ret = 0;
    }
    else if (member(tree[parent], "parents") && sizeof(tree[parent]["parents"]))
    {
        foreach(string grandparent in tree[parent]["parents"])
        {
            ret &&= validateRelationship(child, grandparent);
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addChild(string child, string parent)
{
    int ret = 0;
    if((child != parent) && getResearchItem(child) && getResearchItem(parent))
    {
        if(!tree[child]["parents"])
        {
            tree[child]["parents"] = ({ });
        }
        if(!tree[parent]["children"])
        {
            tree[parent]["children"] = ({ });
        }
        
        ret = validateRelationship(child, parent);
        if (ret)
        {
            tree[child]["parents"] += ({ parent });
            tree[parent]["children"] += ({ child });
        }
        else
        {
            raise_error(sprintf("ERROR - researchTree: The relationship for "
                "child (%s) and parent (%s) results in infinite recursion.\n",
                child, parent));
        }
    }
    else
    {
        raise_error(sprintf("ERROR - researchTree: The child (%s) and "
            "parent (%s) must be unique valid researchItem objects.\n", 
            child, parent));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addResearchElement(string location)
{
    int ret = 0;
    
    if(getResearchItem(location))
    {
        if(!member(tree, location))
        {
            tree[location] = ([
                "parents": 0,
                "children": 0
            ]);
            ret = 1;
        }
        else
        {
            raise_error(sprintf("ERROR - researchTree: The research item "
                "%s is already a member of the research tree.\n", 
                location));
        }
    }
    else
    {
        raise_error("ERROR - researchTree: The research element must exist"
            " in the location passed to this method and be a valid "
            "object before it can be added to any trees.\n");
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *getParents(string researchItem)
{
    string *ret = ({});
    if (member(tree, researchItem) && 
        member(tree[researchItem], "parents") &&
        sizeof(tree[researchItem]["parents"]))
    {
        ret += tree[researchItem]["parents"];
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string getNodeInfo(string element, object owner,
    int level)
{
    string ret = "";

    if (element && stringp(element) && member(tree, element) &&
        researchDictionary()->researchObject(element))
    {
        object researchItem = getResearchItem(element);
        if (!tree[element]["children"])
        {
            string displayColor = "[0;31m";
            if (owner->isResearched(element))
            {
                displayColor = "[0;34;1m";
            }
            else if (owner->isResearching(element))
            {
                displayColor = "[0;35m";
            }
            else if (owner->canResearch(element))
            {
                displayColor = "[0;33m";
            }
            ret += sprintf("[0;30;1m%" + (level * 6) + "s%s%s[0m\n",
                "|-- ", 
                displayColor, 
                capitalize(researchItem->query("name")));
        }
        else if (pointerp(tree[element]["children"]) &&
            sizeof(tree[element]["children"]) &&
            stringp(tree[element]["children"][0]))
        {
            string displayColor = "[0;31m";
            if (owner->isResearched(element))
            {
                displayColor = "[0;34;1m";
            }
            else if (owner->isResearching(element))
            {
                displayColor = "[0;35m";
            }
            else if (owner->canResearch(element))
            {
                displayColor = "[0;33m";
            }
            researchItem = getResearchItem(element);
            ret += sprintf("[0;30;1m%" + (level * 6) + "s%s%s[0m\n", 
                (level ? "|-- " : ""), 
                displayColor,
                capitalize(researchItem->query("name")));
            foreach(string child in tree[element]["children"])
            {
                ret += getNodeInfo(child, owner, level + 1);
            }
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string researchTreeDetails(object user)
{
    string ret = sprintf(FieldDisplay, "Research Tree", capitalize(Name())) +
        sprintf(Value, Description()) + "\n" +
        displayPrerequisites() + 
        "[0;33mThe tree offers the following research items:[0m\n";

    if (treeRoot)
    {
        ret += getNodeInfo(treeRoot, user, 0);
    }
    return ret;
}