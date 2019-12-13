//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

int AllowFrom = 1;
int AllowTo = 1;
int isLight = 0;

/////////////////////////////////////////////////////////////////////////////
public void toggleAllowFrom()
{
    AllowFrom = !AllowFrom;
}

/////////////////////////////////////////////////////////////////////////////
public void toggleAllowTo()
{
    AllowTo = !AllowTo;
}

/////////////////////////////////////////////////////////////////////////////
public void toggleLight()
{
    isLight = !isLight;
}

/////////////////////////////////////////////////////////////////////////////
protected int alwaysLight()
{
    return isLight;
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    return AllowFrom;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    return AllowTo;
}

/////////////////////////////////////////////////////////////////////////////
public int isValidEnvironment()
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public varargs string long(string item)
{
    string ret = "This is the long description.\n";
    if (!isIlluminated())
    {
        ret = "It is too dark.\n";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
void catch_tell(string x)
{
    write(x);
}
