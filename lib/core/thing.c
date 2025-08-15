//*****************************************************************************
// Class: thing
// File Name: thing.c
//
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//
// Description: Thing is the base object for all basic lib objects contained
//              within the base Realms object library. It provides access to
//              dictionaries and the message parser as well as integration
//              with the various lib modules.
//
//*****************************************************************************
private nosave string LibDirectory = "/lib";
private nosave object MessageParser = 0;

//-----------------------------------------------------------------------------
// Method: has
// Description: This method returns true if the Thing being queried has been
//              integrated with one of the core library modules.
//
// Parameters: service - the module to check for
//
// Returns: true if this 'thing' uses the queried module
//-----------------------------------------------------------------------------
public int has(string service)
{
    int ret = 0;
    
    if(this_object() && service && stringp(service) && 
        (member(inherit_list(this_object()), 
            sprintf("%s/modules/%s.c", LibDirectory, service)) > -1))
    {
        ret = 1;
    }
    else if (this_object() && service && stringp(service) && 
        (member(inherit_list(this_object()),
        sprintf("%s/core/%s.c", LibDirectory, service)) > -1))
    {
        ret = 1;
    }
    return ret;
}

//-----------------------------------------------------------------------------
// Method: getModule
// Description: This method returns the module object for the queried service
//              if it has been integrated with this instance of Thing.
//
// Parameters: service - the module to check for
//
// Returns: the module object if this 'thing' uses the queried module
//-----------------------------------------------------------------------------
protected object getModule(string service)
{
    object ret = 0;
    if(has(service))
    {
        ret = this_object();
    }
    else if(this_object() && function_exists("isRealizationOf", this_object()))
    {
        ret = call_other(this_object(), "isRealizationOf", service);
    }

    return ret;
}

//-----------------------------------------------------------------------------
// Method: getMessageParser
// Description: This method returns the core lib message parser object. It will 
//              load the message parser blueprint if it is not already loaded 
//              by the driver.
//
// Returns: the core lib message parser object
//-----------------------------------------------------------------------------
protected object getMessageParser()
{
    if (!MessageParser)
    {
        MessageParser = 
            load_object(sprintf("/%s/core/messageParser.c", LibDirectory));
    }
    return MessageParser;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int isIlluminated()
{
    return environment() ? environment()->isIlluminated() : 10;
}
