//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef experiencesModule_h
#define experiencesModule_h

private mapping *observations = ({ });
private nosave mapping *pendingObservations = ({ });
private nosave int observationsPersisted;
private nosave string observationsPlayerName = "";

private nomask string *pendingObservationIds()
{
    return map(pendingObservations, (: $1["ID"] :));
}

private nosave mapping observationTypeIndex = ([]);

private nomask void indexObservation(mapping observation)
{
    if (stringp(observation["type"]) && observation["type"] != "")
    {
        string type = lower_case(observation["type"]);
        for (int index = 1; index <= sizeof(type); index++)
        {
            if (index == sizeof(type) || type[index] == '.')
            {
                string prefix = type[0..(index - 1)];
                if (!member(observationTypeIndex, prefix))
                {
                    observationTypeIndex[prefix] = ({ });
                }
                observationTypeIndex[prefix] += ({ observation });
            }
        }
    }
}

private nomask mapping *observationCandidates(mapping criteria)
{
    mapping *ret = observations;
    if (mappingp(criteria) && stringp(criteria["type"]))
    {
        string type = lower_case(criteria["type"]);
        ret = member(observationTypeIndex, type) ?
            observationTypeIndex[type] : ({ });
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mixed cloneExperiencesValue(mixed value)
{
    mixed ret = value;

    if (pointerp(value))
    {
        ret = ({ });
        foreach(mixed item in value)
        {
            ret += ({ cloneExperiencesValue(item) });
        }
    }
    else if (mappingp(value))
    {
        ret = ([]);
        foreach(mixed key in m_indices(value))
        {
            ret[key] = cloneExperiencesValue(value[key]);
        }
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private nomask mapping cloneObservationEntry(mapping observation)
{
    return mappingp(observation) ? cloneExperiencesValue(observation) : ([]);
}

/////////////////////////////////////////////////////////////////////////////
static nomask void loadExperiences(mapping data, object persistence)
{
    if (isValidPersistenceObject(persistence))
    {
        mixed savedData = persistence->extractSaveData("experiences", data);

        observations = ({ });
        observationTypeIndex = ([]);
        pendingObservations = ({ });
        observationsPersisted = data["experiences persisted"] &&
            !data["is guest"];
        observationsPlayerName = stringp(data["name"]) ?
            lower_case(data["name"]) : "";

        if (pointerp(savedData))
        {
            foreach(mixed observation in savedData)
            {
                if (mappingp(observation))
                {
                    mapping entry = cloneObservationEntry(observation);
                    observations += ({ entry });
                    indexObservation(entry);
                    if (!observationsPersisted)
                    {
                        pendingObservations += ({ entry });
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
static nomask mapping sendExperiences()
{
    return ([
        "experiences": map(pendingObservations, #'cloneObservationEntry)
    ]);
}

static nomask void acknowledgeExperiences(mapping *saved)
{
    string *ids = map(saved, (: $1["ID"] :));
    pendingObservations = filter(pendingObservations,
        (: member($2, $1["ID"]) < 0 :), ids);
    observationsPersisted = 1;
    observationsPlayerName = lower_case(this_object()->Name());
    if (sizeof(observations) > 100)
    {
        observations = observations[(sizeof(observations) - 100)..];
        observationTypeIndex = ([]);
        foreach(mapping entry in observations)
        {
            indexObservation(entry);
        }
    }
}

#endif