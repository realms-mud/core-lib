//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

private string *attributes = ({
    "strength",
    "intelligence",
    "wisdom",
    "dexterity",
    "constitution",
    "charisma"
});

private string *bonusAttributes = ({ });

/////////////////////////////////////////////////////////////////////////////
public nomask int isValidAttribute(string attribute)
{
    return member(attributes, attribute) > -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *attributes()
{
    return attributes + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *bonusAttributes()
{
    if (!sizeof(bonusAttributes))
    {
        foreach(string attribute in attributes)
        {
            bonusAttributes += ({ sprintf("bonus %s", attribute) });
        }
    }
    return bonusAttributes + ({});
}
