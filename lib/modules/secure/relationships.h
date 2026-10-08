//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef relationshipsModule_h
#define relationshipsModule_h

private mapping relationships = ([]);
private mapping incomingRelationships = ([]);
private mapping relationshipHistory = ([]);
private nosave mapping derivedRelationships = ([]);

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneRelationshipEntry(mapping relationship)
{
    mapping ret = relationship + ([]);

    if (member(ret, "dimensions") && mappingp(ret["dimensions"]))
    {
        ret["dimensions"] = ret["dimensions"] + ([]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneHistoryEntry(mapping entry)
{
    mapping ret = entry + ([]);

    if (member(ret, "context") && mappingp(ret["context"]))
    {
        ret["context"] = ret["context"] + ([]);
    }
    if (member(ret, "metadata") && mappingp(ret["metadata"]))
    {
        ret["metadata"] = ret["metadata"] + ([]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneRelationshipMap(mapping data)
{
    mapping ret = ([]);

    if (mappingp(data))
    {
        foreach(string key in m_indices(data))
        {
            if (mappingp(data[key]))
            {
                ret[key] = cloneRelationshipEntry(data[key]);
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneRelationshipHistory(mapping data)
{
    mapping ret = ([]);

    if (mappingp(data))
    {
        foreach(string key in m_indices(data))
        {
            ret[key] = ({ });

            if (pointerp(data[key]))
            {
                foreach(mapping historyEntry in data[key])
                {
                    ret[key] += ({ cloneHistoryEntry(historyEntry) });
                }
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
static nomask void loadRelationships(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        derivedRelationships = ([]);
        mapping savedRelationships =
            persistence->extractSaveData("relationships", data);
        if (mappingp(savedRelationships))
        {
            relationships = cloneRelationshipMap(savedRelationships);
        }

        mapping savedHistory =
            persistence->extractSaveData("relationshipHistory", data);
        if (mappingp(savedHistory))
        {
            relationshipHistory = cloneRelationshipHistory(savedHistory);
        }
        mapping savedIncoming =
            persistence->extractSaveData("incomingRelationships", data);
        incomingRelationships = mappingp(savedIncoming) ?
            cloneRelationshipMap(savedIncoming) : ([]);
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendRelationships()
{
    return ([
        "relationships": cloneRelationshipMap(relationships),
        "incomingRelationships":cloneRelationshipMap(incomingRelationships),
        "relationshipHistory": cloneRelationshipHistory(relationshipHistory)
    ]);
}

#endif
