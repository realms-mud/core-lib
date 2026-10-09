//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *worldRelationships(string source, string target)
{
    if (sizeof(regexp(({ source, target }),
        "^/lib/realizations/player[.]c#")))
    {
        raise_error("ERROR - world relationships: Player identities require "
            "a live player relationship module.\n");
    }
    mapping records = ([]);
    int handle = connect();
    string query = sprintf("select targetKey, dimension, value, revision, "
        "updated from worldRelationshipDimensions where sourceKey = '%s'",
        sanitizeString(source));
    if (target != "")
    {
        query += sprintf(" and targetKey = '%s'", sanitizeString(target));
    }
    db_exec(handle, query + ";");
    if (db_error(handle))
    {
        string error = db_error(handle);
        disconnect(handle);
        raise_error("ERROR - world relationships query: " + error + "\n");
    }
    else
    {
        mixed row;
        while (row = db_fetch(handle))
        {
            string key = convertString(row[0]);
            if (!member(records, key))
            {
                records[key] = ([
                    "source":source,
                    "target":key,
                    "dimensions":([]),
                    "revision":0,
                    "updated":to_int(row[4])
                ]);
            }
            records[key]["dimensions"][convertString(row[1])] =
                to_int(row[2]);
            records[key]["revision"] += to_int(row[3]);
            if (to_int(row[4]) > records[key]["updated"])
            {
                records[key]["updated"] = to_int(row[4]);
            }
        }
        disconnect(handle);
    }
    return m_values(records);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping changeWorldRelationship(string source, string target,
    mapping changes)
{
    object service = getService("relationship");
    mapping ret = ([]);
    if (service->identity(source) == "" ||
        service->identity(target) == "" || source == target ||
        !service->validChanges(changes) ||
        sizeof(regexp(({ source, target }),
            "^/lib/realizations/player[.]c#")))
    {
        raise_error("ERROR - world relationships: Invalid change.\n");
    }
    else
    {
        int handle = connect();
        db_exec(handle, "start transaction;");
        string error = db_error(handle);
        foreach(string dimension in sort_array(m_indices(changes),
            (: $1 > $2 :)))
        {
            if (!error)
            {
                int *bounds = service->dimensionBounds(dimension);
                int delta = changes[dimension];
                delta = delta > 200 ? 200 : (delta < -200 ? -200 : delta);
                db_exec(handle, sprintf(
                    "call changeWorldRelationshipDimension("
                    "'%s', '%s', '%s', %d, %d, %d, %d);",
                    sanitizeString(source), sanitizeString(target),
                    sanitizeString(dimension), delta, bounds[0], bounds[1],
                    time()));
                error = db_error(handle);
                while (db_fetch(handle));
            }
        }
        if (!error)
        {
            db_exec(handle, "commit;");
            error = db_error(handle);
        }
        if (error)
        {
            db_exec(handle, "rollback;");
        }
        disconnect(handle);
        if (error)
        {
            raise_error("ERROR - world relationships save: " + error + "\n");
        }
        else
        {
            mapping *records = worldRelationships(source, target);
            ret = records[0];
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string serializeMapping(mapping data)
{
    string ret = "";

    if (mappingp(data))
    {
        foreach(string key in m_indices(data))
        {
            ret += sprintf("%s:=:%O##", key, data[key]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed parseScalar(string value)
{
    mixed ret = value;

    if (stringp(value) &&
        (sizeof(regexp(({ value }), "^[0-9]+$")) ||
            sizeof(regexp(({ value }), "^-[0-9]+$"))))
    {
        ret = to_int(value);
    }
    else if (stringp(value) && sizeof(regexp(({ value }), "^\".*\"$")))
    {
        ret = value[1..(sizeof(value) - 2)];
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping deserializeMapping(string data)
{
    mapping ret = ([]);

    if (stringp(data) && (data != ""))
    {
        foreach(string item in explode(data, "##") - ({ "" }))
        {
            string key = "";
            string value = "";

            if (sscanf(item, "%s:=:%s", key, value) == 2)
            {
                ret[key] = parseScalar(value);
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getResearchMentorships(int playerId, int handle)
{
    mapping ret = ([ "researchMentorships":([]) ]);
    db_exec(handle, sprintf("select researchKey, teacherKey, changes "
        "from researchMentorships where playerId = %d;", playerId));
    if (db_error(handle))
    {
        raise_error("ERROR - mentorship load: " + db_error(handle) + "\n");
    }
    mixed row;
    while (row = db_fetch(handle))
    {
        ret["researchMentorships"][convertString(row[0])] = ([
            "teacher":convertString(row[1]),
            "changes":deserializeMapping(convertString(row[2]))
        ]);
    }

    if (!sizeof(ret["researchMentorships"]))
    {
        m_delete(ret, "researchMentorships");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveResearchMentorships(int handle, int playerId,
    mapping playerData)
{
    if (mappingp(playerData["researchMentorships"]))
    {
        db_exec(handle, sprintf("call pruneResearchMentorships(%d);", playerId));
        if (db_error(handle))
        {
            raise_error("ERROR - mentorship prune: " + db_error(handle) + "\n");
        }
        while (db_fetch(handle));
        foreach(string item in m_indices(playerData["researchMentorships"]))
        {
            mapping lesson = playerData["researchMentorships"][item];
            if (!mappingp(lesson) ||
                getService("relationship")->identity(lesson["teacher"]) == "" ||
                !getService("relationship")->validChanges(lesson["changes"]))
            {
                raise_error("ERROR - mentorship save: Invalid lesson.\n");
            }
            db_exec(handle, sprintf(
                "call saveResearchMentorship(%d, '%s', '%s', '%s');",
                playerId, sanitizeString(item),
                sanitizeString(lesson["teacher"]),
                sanitizeString(serializeMapping(lesson["changes"]))));
            if (db_error(handle))
            {
                raise_error("ERROR - mentorship save: " +
                    db_error(handle) + "\n");
            }
            while (db_fetch(handle));
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
private nomask int playerIdByName(string playerName, int dbHandle)
{
    int ret = 0;

    string query = sprintf("select id from players where name = '%s';",
        sanitizeString(lower_case(playerName)));
    db_exec(dbHandle, query);
    mixed result = db_fetch(dbHandle);

    if (result)
    {
        ret = to_int(result[0]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping relationshipByPlayerIdAndTarget(int playerId,
    string targetKey, int dbHandle)
{
    mapping ret = ([]);

    string query = sprintf("select r.targetKey, r.updated, d.dimension, d.value "
        "from relationships r "
        "left outer join relationshipDimensions d on d.relationshipId = r.id "
        "where r.playerId = %d and r.targetKey = '%s' "
        "order by d.dimension;", playerId, sanitizeString(targetKey));

    db_exec(dbHandle, query);

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            if (!sizeof(ret))
            {
                ret = ([
                    "target": convertString(result[0]),
                    "dimensions": ([]),
                    "updated": to_int(result[1])
                ]);
            }

            if (convertString(result[2]) != "")
            {
                ret["dimensions"][convertString(result[2])] = to_int(result[3]);
            }
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping relationshipByPlayerAndTarget(string playerName,
    string targetKey)
{
    mapping ret = ([]);

    int dbHandle = connect();
    int playerId = playerIdByName(playerName, dbHandle);

    if (playerId && stringp(targetKey))
    {
        ret = relationshipByPlayerIdAndTarget(playerId, targetKey, dbHandle);
    }

    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int relationshipDimensionByPlayerAndTarget(string playerName,
    string targetKey, string dimension)
{
    int ret = 0;
    mapping relationship = relationshipByPlayerAndTarget(playerName, targetKey);

    if (mappingp(relationship) && member(relationship, "dimensions") &&
        member(relationship["dimensions"], dimension))
    {
        ret = to_int(relationship["dimensions"][dimension]);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int hasRelationshipByPlayerAndTarget(string playerName,
    string targetKey)
{
    return sizeof(relationshipByPlayerAndTarget(playerName, targetKey));
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *queryRelationshipsByPlayer(string playerName,
    mapping query)
{
    mapping *ret = ({ });

    int dbHandle = connect();
    int playerId = playerIdByName(playerName, dbHandle);

    if (playerId)
    {
        string queryString = sprintf("select targetKey from relationships "
            "where playerId = %d order by targetKey;", playerId);
        db_exec(dbHandle, queryString);

        mixed result;
        string *targets = ({ });
        do
        {
            result = db_fetch(dbHandle);
            if (result)
            {
                targets += ({ convertString(result[0]) });
            }
        } while (result);
        foreach(string target in targets)
        {
            mapping relationship = relationshipByPlayerIdAndTarget(playerId,
                target, dbHandle);
            if (getService("relationship")->matchesQuery(relationship, query))
            {
                ret += ({ relationship });
            }
        }
    }

    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping *relationshipHistoryByPlayerAndTarget(string playerName,
    string targetKey, mapping query)
{
    mapping *ret = ({ });

    int dbHandle = connect();
    int playerId = playerIdByName(playerName, dbHandle);

    if (playerId)
    {
        string queryString = sprintf("select h.dimension, h.delta, h.value, "
            "h.timestamp, h.producer, h.context, h.metadata "
            "from relationships r "
            "inner join relationshipHistory h on h.relationshipId = r.id "
            "where r.playerId = %d and r.targetKey = '%s' "
            "order by h.id;", playerId, sanitizeString(targetKey));

        db_exec(dbHandle, queryString);

        mixed result;
        do
        {
            result = db_fetch(dbHandle);
            if (result)
            {
                mapping entry = ([
                    "target": targetKey,
                    "dimension": convertString(result[0]),
                    "delta": to_int(result[1]),
                    "value": to_int(result[2]),
                    "timestamp": to_int(result[3]),
                    "producer": convertString(result[4]),
                    "context": deserializeMapping(convertString(result[5])),
                    "metadata": deserializeMapping(convertString(result[6]))
                ]);

                int matches = 1;
                if (mappingp(query) && sizeof(query))
                {
                    foreach(string key in m_indices(query))
                    {
                        if (!member(entry, key) || (entry[key] != query[key]))
                        {
                            matches = 0;
                            break;
                        }
                    }
                }

                if (matches)
                {
                    ret += ({ entry });
                }
            }
        } while (result);
    }

    disconnect(dbHandle);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping updateRelationshipByPlayerAndTarget(string playerName,
    string targetKey, mapping dimensionChanges, mapping context,
    mapping metadata, string producer)
{
    mapping ret = ([]);

    if (!stringp(playerName) || playerName == "" ||
        getService("relationship")->identity(targetKey) == "" ||
        !getService("relationship")->validChanges(dimensionChanges))
    {
        raise_error("ERROR - relationships data service: Invalid update.\n");
    }
    else
    {
        int dbHandle = connect();
        int playerId = playerIdByName(playerName, dbHandle);

        if (playerId)
        {
            mapping relationship = relationshipByPlayerIdAndTarget(playerId,
                targetKey, dbHandle);
            mapping dimensions = member(relationship, "dimensions") ?
                relationship["dimensions"] + ([]) : ([]);

            dimensions = getService("relationship")->applyChanges(
                dimensions, dimensionChanges);

            int updated = time();
            string queryString = sprintf("call saveRelationship(%d, '%s', %d);",
                playerId, sanitizeString(targetKey), updated);
            db_exec(dbHandle, queryString);
            mixed result = db_fetch(dbHandle);

            foreach(string dimension in m_indices(dimensions))
            {
                queryString = sprintf("call saveRelationshipDimension(%d, '%s', '%s', %d);",
                    playerId,
                    sanitizeString(targetKey),
                    sanitizeString(dimension),
                    to_int(dimensions[dimension]));
                db_exec(dbHandle, queryString);
                result = db_fetch(dbHandle);
            }

            ret = ([
                "target": targetKey,
                "dimensions": dimensions,
                "updated": updated
            ]);
        }

        disconnect(dbHandle);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void clearRelationshipsByPlayer(string playerName)
{
    int dbHandle = connect();
    int playerId = playerIdByName(playerName, dbHandle);

    if (playerId)
    {
        string query = sprintf("call pruneRelationships(%d);", playerId);
        db_exec(dbHandle, query);
        mixed result = db_fetch(dbHandle);
    }

    disconnect(dbHandle);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getRelationships(int playerId, int dbHandle,
    string playerName)
{
    mapping ret = ([
        "relationships": ([]),
        "relationshipHistory": ([]),
        "incomingRelationships":([])
    ]);

    string source = sprintf("/lib/realizations/player#%s",
        capitalize(playerName));

    string query = sprintf("select targetKey from relationships "
        "where playerId = %d order by targetKey;", playerId);
    db_exec(dbHandle, query);

    mixed result;
    string *targets = ({ });
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            targets += ({ convertString(result[0]) });
        }
    } while (result);

    foreach(string target in targets)
    {
            mapping relationship =
                relationshipByPlayerIdAndTarget(playerId, target, dbHandle);
            relationship["source"] = source;
            ret["relationships"][target] = relationship;

            ret["relationshipHistory"][target] = ({ });
            string historyQuery = sprintf("select h.dimension, h.delta, h.value, "
                "h.timestamp, h.producer, h.context, h.metadata "
                "from relationships r "
                "inner join relationshipHistory h on h.relationshipId = r.id "
                "where r.playerId = %d and r.targetKey = '%s' order by h.id;",
                playerId, sanitizeString(target));
            db_exec(dbHandle, historyQuery);

            mixed historyResult;
            do
            {
                historyResult = db_fetch(dbHandle);
                if (historyResult)
                {
                    ret["relationshipHistory"][target] += ({ ([
                        "source": source,
                        "target": target,
                        "dimension": convertString(historyResult[0]),
                        "delta": to_int(historyResult[1]),
                        "value": to_int(historyResult[2]),
                        "timestamp": to_int(historyResult[3]),
                        "producer": convertString(historyResult[4]),
                        "context": deserializeMapping(convertString(historyResult[5])),
                        "metadata": deserializeMapping(convertString(historyResult[6]))
                    ]) });
                }
            } while (historyResult);
    }

    query = sprintf("select sourceKey, dimension, value, updated "
        "from incomingRelationshipDimensions where playerId = %d;",
        playerId);
    db_exec(dbHandle, query);
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            string key = convertString(result[0]);
            if (!member(ret["incomingRelationships"], key))
            {
                ret["incomingRelationships"][key] = ([
                    "source":key,
                    "target":source,
                    "dimensions":([]),
                    "updated":to_int(result[3])
                ]);
            }
            ret["incomingRelationships"][key]["dimensions"][
                convertString(result[1])] = to_int(result[2]);
        }
    } while (result);

    if (!sizeof(ret["incomingRelationships"]))
    {
        m_delete(ret, "incomingRelationships");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveRelationships(int dbHandle, int playerId,
    mapping playerData)
{
    if (member(playerData, "relationships") && mappingp(playerData["relationships"]))
    {
        string query;
        mixed result;

        foreach(string target in m_indices(playerData["relationships"]))
        {
            mapping relationship = playerData["relationships"][target];
            query = sprintf("call saveRelationship(%d, '%s', %d);",
                playerId,
                sanitizeString(target),
                to_int(relationship["updated"]));
            db_exec(dbHandle, query);
            if (db_error(dbHandle))
            {
                raise_error("ERROR - relationship save: " +
                    db_error(dbHandle) + "\n");
            }
            result = db_fetch(dbHandle);

            if (member(relationship, "dimensions") &&
                mappingp(relationship["dimensions"]))
            {
                foreach(string dimension in m_indices(relationship["dimensions"]))
                {
                    query = sprintf("call saveRelationshipDimension(%d, '%s', '%s', %d);",
                        playerId,
                        sanitizeString(target),
                        sanitizeString(dimension),
                        to_int(relationship["dimensions"][dimension]));
                    db_exec(dbHandle, query);
                    if (db_error(dbHandle))
                    {
                        raise_error("ERROR - relationship dimension save: " +
                            db_error(dbHandle) + "\n");
                    }
                    result = db_fetch(dbHandle);
                }
            }
        }

        if (member(playerData, "relationshipHistory") &&
            mappingp(playerData["relationshipHistory"]))
        {
            foreach(string target in m_indices(playerData["relationshipHistory"]))
            {
                if (pointerp(playerData["relationshipHistory"][target]))
                {
                    foreach(mapping history in playerData["relationshipHistory"][target])
                    {
                        query = sprintf("call saveRelationshipHistory(%d, '%s', '%s', %d, %d, %d, '%s', '%s', '%s');",
                            playerId,
                            sanitizeString(target),
                            sanitizeString(history["dimension"]),
                            to_int(history["delta"]),
                            to_int(history["value"]),
                            to_int(history["timestamp"]),
                            sanitizeString(history["producer"]),
                            sanitizeString(serializeMapping(history["context"])),
                            sanitizeString(serializeMapping(history["metadata"])));
                        db_exec(dbHandle, query);
                        if (db_error(dbHandle))
                        {
                            raise_error("ERROR - relationship history save: " +
                                db_error(dbHandle) + "\n");
                        }
                        result = db_fetch(dbHandle);
                    }
                }
            }
        }
    }
    if (mappingp(playerData["incomingRelationships"]))
    {
        foreach(string source in m_indices(playerData["incomingRelationships"]))
        {
            mapping record = playerData["incomingRelationships"][source];
            foreach(string dimension in m_indices(record["dimensions"]))
            {
                string incomingQuery = sprintf(
                    "call saveIncomingRelationshipDimension("
                    "%d, '%s', '%s', %d, %d);",
                    playerId, sanitizeString(source),
                    sanitizeString(dimension),
                    record["dimensions"][dimension], record["updated"]);
                db_exec(dbHandle, incomingQuery);
                if (db_error(dbHandle))
                {
                    raise_error("ERROR - incoming relationship save: " +
                        db_error(dbHandle) + "\n");
                }
                mixed incomingResult = db_fetch(dbHandle);
            }
        }
    }
}
