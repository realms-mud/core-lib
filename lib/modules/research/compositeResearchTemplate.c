//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/research/activeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask int addSpecification(string type, mixed value)
{
    int ret = 0;

    switch(type)
    {  
        case "segments":
        {
            if(value && pointerp(value) && sizeof(value) && 
                mappingp(value[0]))
            {
                specificationData[type] = value;
                ret = 1;           
            }
            else
            {
                raise_error(sprintf("ERROR - compositeResearchTemplate: "
                    "the '%s' specification must be a valid segment array.\n", 
                    type));
            }
            break;
        }      
    }

    if(!ret)
    {
        ret = activeResearchItem::addSpecification(type, value);
    }
    return ret;
}
