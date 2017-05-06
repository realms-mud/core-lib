//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/core/thing";

private int useTrait = 0;
private string *traits = ({});

/////////////////////////////////////////////////////////////////////////////
public void ToggleMockTrait()
{
    useTrait = !useTrait;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isTraitOf(string trait)
{
    return member(traits, trait) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidTrait(string trait)
{
    return useTrait;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping characterCreationTraits()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping Traits()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int addTrait(string trait)
{
    traits += ({ trait });
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int removeTrait(string trait)
{
    traits -= ({ trait });
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *traitsExtraAttacks()
{
    return useTrait ? ({ (["attack type":"fire", "to hit" : 20, "damage" : 10]) }) : ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitsAttributeBonus(string attribute)
{
    return useTrait;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int traitsBonusTo(string bonus)
{
    return useTrait * 2;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *traitsResearchTrees()
{
    string *ret = ({});
    if (useTrait)
    {
        ret = ({ "does/not/exist/traitResearchTree.c", "some/other/locale/traitResearchTree.c" });
    }
    return ret;
}

