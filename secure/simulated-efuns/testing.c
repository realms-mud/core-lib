//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private object *CannedUserList = ({});
private object RestoreCaller = 0;
private string *TestingGroups = ({ });
private int ShortCircuitCallOuts;

/////////////////////////////////////////////////////////////////////////////
public nomask void setUpForTesting()
{

}

/////////////////////////////////////////////////////////////////////////////
public nomask object *cannedUserList()
{
    return CannedUserList;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setUsers(object *list)
{
    CannedUserList = list;
}

/////////////////////////////////////////////////////////////////////////////
public nomask object restoreCaller()
{
    return RestoreCaller;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setRestoreCaller(object restorer)
{
    if (objectp(restorer))
    {
        RestoreCaller = restorer;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *testingGroups()
{
    return TestingGroups;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void setCustomGroups(string *list)
{
    TestingGroups = list + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask void ToggleCallOutBypass()
{
    ShortCircuitCallOuts = !ShortCircuitCallOuts;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void call_out(string method, int delay, varargs mixed *data)
{
    if (ShortCircuitCallOuts && previous_object())
    {
        apply(#'call_direct,previous_object(),method,data);
    }
    else
    {
        apply(#'efun::call_out,method,delay,data);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int exec(object newObject, object oldObject)
{
    printf("Exec of %O to %O.\n", oldObject, newObject);
    return 1;
}
