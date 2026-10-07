//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/secure/dataServices/dataService.c";

#define EXPERIENCES_SERIALIZATION_MARKER "@experiences-v2@"
#define LEGACY_EXPERIENCES_SERIALIZATION_MARKER "@experience-v1@"

/////////////////////////////////////////////////////////////////////////////
private nomask string encodeExperiencesValue(mixed value)
{
    string ret = "";
    string payload = "";
    string type = "string";

    if (mappingp(value))
    {
        type = "mapping";
        payload = sprintf("%d:", sizeof(value));

        foreach(mixed key in m_indices(value))
        {
            payload += encodeExperiencesValue(key) +
                encodeExperiencesValue(value[key]);
        }
    }
    else if (pointerp(value))
    {
        type = "array";
        payload = sprintf("%d:", sizeof(value));

        foreach(mixed item in value)
        {
            payload += encodeExperiencesValue(item);
        }
    }
    else if (intp(value))
    {
        type = "integer";
        payload = sprintf("%d", value);
    }
    else if (floatp(value))
    {
        type = "float";
        payload = sprintf("%O", value);
    }
    else if (objectp(value))
    {
        payload = sprintf("%s#%s", program_name(value),
            function_exists("Name", value) && value->Name() ?
                value->Name() : "any");
    }
    else if (stringp(value))
    {
        payload = value;
    }
    else
    {
        payload = sprintf("%O", value);
    }

    ret = sprintf("%s:%d:%s", type, sizeof(payload), payload);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int colonPosition(string data)
{
    int ret = -1;

    if (stringp(data))
    {
        for (int index = 0; index < sizeof(data) && (ret < 0); index++)
        {
            if (data[index..index] == ":")
            {
                ret = index;
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping decodeExperiencesValue(string data)
{
    mapping ret = ([ "value": "", "length": 0 ]);

    if (stringp(data) && sizeof(data) > 2)
    {
        int separator = colonPosition(data);

        if (separator > 1)
        {
            string type = data[0..(separator - 1)];
            string lengthText = "";
            int payloadOffset = separator + 1;

            int lengthSeparator = colonPosition(data[payloadOffset..]);
            if (lengthSeparator > 0)
            {
                lengthText = data[payloadOffset..
                    (payloadOffset + lengthSeparator - 1)];
                payloadOffset += lengthSeparator + 1;
            }

            int payloadLength = to_int(lengthText);
            if (sizeof(regexp(({ lengthText }), "^[0-9]+$")) &&
                payloadLength >= 0 && payloadOffset <= sizeof(data) &&
                payloadLength <= sizeof(data) - payloadOffset &&
                member(({ "string", "mapping", "array", "integer",
                    "float" }), type) >= 0)
            {
                int totalLength = payloadOffset + payloadLength;
                string payload = payloadLength ?
                    data[payloadOffset..(totalLength - 1)] : "";
                mixed value = payload;
                int valid = 1;

                if (type == "integer")
                {
                    value = to_int(payload);
                }
                else if (type == "float")
                {
                    value = to_float(payload);
                }
                else if ((type == "array") || (type == "mapping"))
                {
                    int countSeparator = colonPosition(payload);
                    valid = 0;

                    if (countSeparator > 0 &&
                        sizeof(regexp(({ payload[0..
                            (countSeparator - 1)] }), "^[0-9]+$")))
                    {
                        int count = to_int(payload[0..(countSeparator - 1)]);
                        int offset = countSeparator + 1;
                        valid = count >= 0;
                        value = (type == "array") ? ({ }) : ([]);

                        for (int index = 0; index < count && valid; index++)
                        {
                            mapping child = decodeExperiencesValue(
                                offset < sizeof(payload) ?
                                    payload[offset..] : "");
                            valid = child["length"] > 0;
                            offset += child["length"];

                            if (valid && type == "array")
                            {
                                value += ({ child["value"] });
                            }
                            else if (valid)
                            {
                                mapping entry = decodeExperiencesValue(
                                    offset < sizeof(payload) ?
                                        payload[offset..] : "");
                                valid = entry["length"] > 0;
                                offset += entry["length"];
                                if (valid)
                                {
                                    value[child["value"]] = entry["value"];
                                }
                            }
                        }
                        valid = valid && offset == sizeof(payload);
                    }
                }

                if (valid)
                {
                    ret = ([ "value": value, "length": totalLength ]);
                }
            }
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int experiencesMarkerLength(string data)
{
    int ret = 0;

    foreach(string marker in ({ EXPERIENCES_SERIALIZATION_MARKER,
        LEGACY_EXPERIENCES_SERIALIZATION_MARKER }))
    {
        if (sizeof(data) >= sizeof(marker) &&
            data[0..(sizeof(marker) - 1)] == marker)
        {
            ret = sizeof(marker);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string serializeArray(string *data)
{
    string ret = "";

    if (pointerp(data))
    {
        ret = EXPERIENCES_SERIALIZATION_MARKER + encodeExperiencesValue(data);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask string *deserializeArray(string data)
{
    string *ret = ({ });

    if (stringp(data) && (data != ""))
    {
        int markerLength = experiencesMarkerLength(data);
        if (markerLength)
        {
            mapping decoded = decodeExperiencesValue(data[markerLength..]);

            if (pointerp(decoded["value"]))
            {
                foreach(mixed item in decoded["value"])
                {
                    ret += ({ stringp(item) ? item : sprintf("%O", item) });
                }
            }
        }
        else
        {
            ret = explode(data, "##");
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
        ret = EXPERIENCES_SERIALIZATION_MARKER + encodeExperiencesValue(data);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed parseScalar(string value)
{
    mixed ret = value;

    if (stringp(value) && sizeof(regexp(({ value }), "^-?[0-9]+$")))
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
        int markerLength = experiencesMarkerLength(data);
        if (markerLength)
        {
            mapping decoded = decodeExperiencesValue(data[markerLength..]);

            if (mappingp(decoded["value"]))
            {
                ret = decoded["value"];
            }
        }
        else
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
    }

    return ret;
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
private nomask string observationPredicate(int playerId, mapping query,
    string *excludedIds)
{
    string ret = sprintf("playerId = %d", playerId);
    if (!mappingp(query))
    {
        ret += " and 0";
    }
    else
    {
        if (member(query, "type"))
        {
            if (stringp(query["type"]) && sizeof(query["type"]))
            {
                string type = lower_case(query["type"]);
                ret += sprintf(" and (searchType = '%s' or "
                    "(searchType >= '%s' and searchType < '%s'))",
                    sanitizeString(type), sanitizeString(type + "."),
                    sanitizeString(type + "/"));
            }
            else
            {
                ret += " and 0";
            }
        }
        foreach(string boundary in ({ "since", "until" }))
        {
            if (member(query, boundary))
            {
                if (intp(query[boundary]) && query[boundary] >= 0)
                {
                    ret += sprintf(" and observationTime %s %d",
                        boundary == "since" ? ">=" : "<=", query[boundary]);
                }
                else
                {
                    ret += " and 0";
                }
            }
        }
        ret += sprintf(" and observationMatches(searchDocument, "
            "observationDecode('%s')) = 1",
            sanitizeString(encodeExperiencesValue(query)));
    }
    if (pointerp(excludedIds) && sizeof(excludedIds))
    {
        string *ids = ({ });
        foreach(mixed id in excludedIds)
        {
            if (stringp(id))
            {
                ids += ({ "'" + sanitizeString(id) + "'" });
            }
        }
        if (sizeof(ids))
        {
            ret += " and observationKey not in (" + implode(ids, ",") + ")";
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping *queryObservationsByPlayerId(int playerId, mapping query,
    int limit, int offset, int dbHandle, string *excludedIds, int latest)
{
    mapping *ret = ({ });

    string queryString = sprintf("select observationKey, observationType, actor, subject, "
        "participants, observationTime, location, observationContext, "
        "observationMetadata from experienceObservations "
        "where %s order by id %s",
        observationPredicate(playerId, query, excludedIds),
        latest ? "desc" : "asc");
    if (limit > 0 || offset > 0)
    {
        queryString += sprintf(" limit %s offset %d",
            limit > 0 ? sprintf("%d", limit) :
                "18446744073709551615", offset > 0 ? offset : 0);
    }
    queryString += ";";
    db_exec(dbHandle, queryString);
    if (db_error(dbHandle))
    {
        raise_error("Observation query failed: " + db_error(dbHandle) + "\n");
    }

    mixed result;
    do
    {
        result = db_fetch(dbHandle);
        if (result)
        {
            mapping observation = ([
                "ID": convertString(result[0]),
                "type": convertString(result[1]),
                "actor": convertString(result[2]),
                "subject": convertString(result[3]),
                "participants": deserializeArray(convertString(result[4])),
                "timestamp": to_int(result[5]),
                "location": convertString(result[6]),
                "context": deserializeMapping(convertString(result[7])),
                "metadata": deserializeMapping(convertString(result[8]))
            ]);

            ret = latest ? ({ observation }) + ret :
                ret + ({ observation });
        }
    } while (result);

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs mapping *queryObservationsByPlayer(string playerName,
    mapping query, int limit, int offset, string *excludedIds)
{
    mapping *ret = ({ });

    int dbHandle = connect();
    int playerId = playerIdByName(playerName, dbHandle);

    if (playerId)
    {
        ret = queryObservationsByPlayerId(playerId, query, limit, offset,
            dbHandle, excludedIds, 0);
    }

    disconnect(dbHandle);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask int observationAggregate(string playerName, mapping query,
    string *excludedIds, int existence)
{
    int ret = 0;
    int dbHandle = connect();
    int playerId = playerIdByName(playerName, dbHandle);
    if (playerId)
    {
        string predicate = observationPredicate(playerId, query, excludedIds);
        string sql = existence ? sprintf("select exists(select 1 from "
            "experienceObservations where %s);", predicate) :
            sprintf("select count(*) from experienceObservations where %s;",
                predicate);
        db_exec(dbHandle, sql);
        if (db_error(dbHandle))
        {
            raise_error("Observation aggregate failed: " +
                db_error(dbHandle) + "\n");
        }
        mixed result = db_fetch(dbHandle);
        if (result)
        {
            ret = to_int(result[0]);
        }
    }
    disconnect(dbHandle);
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int countObservationsByPlayer(string playerName,
    mapping query, string *excludedIds)
{
    return observationAggregate(playerName, query, excludedIds, 0);
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int hasObservationByPlayer(string playerName,
    mapping query, string *excludedIds)
{
    return observationAggregate(playerName, query, excludedIds, 1);
}

/////////////////////////////////////////////////////////////////////////////
public nomask mapping recordObservation(string playerName,
    mapping observation)
{
    mapping ret = ([]);

    if (stringp(playerName) && mappingp(observation))
    {
        int dbHandle = connect();
        int playerId = playerIdByName(playerName, dbHandle);

        if (playerId)
        {
            if (!member(observation, "actor") || !stringp(observation["actor"]))
            {
                observation["actor"] = sprintf("/lib/realizations/player#%s",
                    capitalize(playerName));
            }
            if (!member(observation, "participants") ||
                !pointerp(observation["participants"]))
            {
                observation["participants"] = ({ });
            }
            if (!member(observation, "context") ||
                !mappingp(observation["context"]))
            {
                observation["context"] = ([]);
            }
            if (!member(observation, "metadata") ||
                !mappingp(observation["metadata"]))
            {
                observation["metadata"] = ([]);
            }
            if (!member(observation, "timestamp") ||
                !intp(observation["timestamp"]))
            {
                observation["timestamp"] = time();
            }
            if (!member(observation, "location") ||
                !stringp(observation["location"]))
            {
                observation["location"] = "";
            }
            if (!member(observation, "subject") ||
                !stringp(observation["subject"]))
            {
                observation["subject"] = "";
            }
            if (!member(observation, "ID") ||
                !stringp(observation["ID"]) ||
                (observation["ID"] == ""))
            {
                observation["ID"] = generateGuid();
            }

            string query = sprintf("call saveExperienceObservation('%s',%d,'%s','%s','%s',"
                "'%s',%d,'%s','%s','%s');",
                sanitizeString(observation["ID"]),
                playerId,
                sanitizeString(lower_case(observation["type"])),
                sanitizeString(observation["actor"]),
                sanitizeString(observation["subject"]),
                sanitizeString(serializeArray(observation["participants"])),
                to_int(observation["timestamp"]),
                sanitizeString(observation["location"]),
                sanitizeString(serializeMapping(observation["context"])),
                sanitizeString(serializeMapping(observation["metadata"])));

            db_exec(dbHandle, query);
            if (db_error(dbHandle))
            {
                raise_error("Observation save failed: " +
                    db_error(dbHandle) + "\n");
            }
            mixed result = db_fetch(dbHandle);

            ret = observation + ([]);
        }

        disconnect(dbHandle);
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
protected nomask mapping getExperiences(int playerId, int dbHandle)
{
    return ([ "experiences": queryObservationsByPlayerId(playerId, ([]),
        100, 0, dbHandle, 0, 1), "experiences persisted": 1 ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void saveExperiences(int dbHandle, int playerId,
    mapping playerData)
{
    if (member(playerData, "experiences") && pointerp(playerData["experiences"]))
    {
        foreach(mapping observation in playerData["experiences"])
        {
            if (!member(observation, "ID") ||
                !stringp(observation["ID"]) ||
                (observation["ID"] == ""))
            {
                observation["ID"] = generateGuid();
            }

            string query = sprintf("call saveExperienceObservation('%s',%d,'%s','%s','%s',"
                "'%s',%d,'%s','%s','%s');",
                sanitizeString(observation["ID"]),
                playerId,
                sanitizeString(observation["type"]),
                sanitizeString(observation["actor"]),
                sanitizeString(observation["subject"]),
                sanitizeString(serializeArray(observation["participants"])),
                to_int(observation["timestamp"]),
                sanitizeString(observation["location"]),
                sanitizeString(serializeMapping(observation["context"])),
                sanitizeString(serializeMapping(observation["metadata"])));

            db_exec(dbHandle, query);
            if (db_error(dbHandle))
            {
                raise_error("Observation save failed: " +
                    db_error(dbHandle) + "\n");
            }
            mixed result = db_fetch(dbHandle);
        }
    }
}