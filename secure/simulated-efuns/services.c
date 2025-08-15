//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private mapping services = ([]);

/////////////////////////////////////////////////////////////////////////////
object getService(string service)
{
    object ret = 0;

    if (member(services, service) && objectp(services[service]))
    {
        ret = services[service];
    }
    else
    {
        string servicePath = stringp(service) ?
            sprintf("/lib/services/%sService.c", service) : 0;

        if (stringp(servicePath) && (file_size(servicePath) > 0))
        {
            ret = load_object(servicePath);
        }
        services[service] = ret;
    }
    return ret;
}
