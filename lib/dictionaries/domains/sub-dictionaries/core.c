//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/dictionaries/domains/building-components.h"
#include "/lib/dictionaries/domains/buildings.h"
#include "/lib/dictionaries/domains/castles.h"
#include "/lib/dictionaries/domains/castle-components.h"
#include "/lib/dictionaries/domains/buildingEffects.h"
#include "/lib/dictionaries/domains/locations.h"
#include "/lib/dictionaries/domains/troops.h"
#include "/lib/dictionaries/domains/troopEffects.h"

protected string DomainSelectorBase = "/lib/modules/domains/%sSelector.c";

protected object configuration =
    load_object("/lib/dictionaries/configurationDictionary.c");

/////////////////////////////////////////////////////////////////////////////
public nomask string generateTitle(string data)
{
    string *words = explode(data, " ");
    int size = sizeof(words);
    for(int i = 0; i < size; i++)
    {
        words[i] = capitalize(words[i]);
    }

    return implode(words, " ");
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs string pluralizeValue(string data, int doNotCapitalize)
{
    string ret = data;
    ret = regreplace(ret, "(s|ch|sh|x|z|dg|o)$", "\\1e");
    ret = regreplace(ret, "([^aeiou])y$", "\\1ie");
    ret += "s";
    ret = regreplace(ret, "(.*)mans$", "\\1men");
    ret = regreplace(ret, "(.*)man-at-armses$", "\\1men-at-arms");

    return doNotCapitalize ? ret : generateTitle(ret);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string generateBuildInfo(string *leftColumn, string *rightColumn)
{
    string ret = "";

    int leftColumnSize = sizeof(leftColumn);
    int rightColumnSize = sizeof(rightColumn);
    int sharedRows = (leftColumnSize > rightColumnSize) ?
        rightColumnSize : leftColumnSize;

    for (int i = 0; i < sharedRows; i++)
    {
        ret += sprintf("%" + sizeof(leftColumn[i]) + "s%s\n",
            leftColumn[i], rightColumn[i]);
    }
    if (leftColumnSize > rightColumnSize)
    {
        ret += implode(leftColumn[rightColumnSize..], "\n");
    }
    else
    {
        for (int i = leftColumnSize; i < rightColumnSize; i++)
        {
            ret += sprintf("%29s%s\n", "", rightColumn[i]);
        }
    }
    return ret;
}
