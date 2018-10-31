//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useBackground = 0;

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockBackground()
{
    useBackground = !useBackground;
    this_object()->resetCaches();
}

/////////////////////////////////////////////////////////////////////////////
public nomask int backgroundBonusTo(string bonus)
{
    return useBackground * 2;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isBackgroundTraitOf(string item)
{
    return useBackground;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *backgroundResearchTrees()
{
    string *ret = ({});
    if (useBackground)
    {
        ret = ({ "does/not/exist/backgroundResearchTree.c", "some/other/locale/backgroundResearchTree.c" });
    }
    return ret;
}

