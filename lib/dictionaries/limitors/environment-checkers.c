//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkEnvironmentLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "environment"))
    {
        object environmentDictionary =
            getDictionary("environment");
        if (environmentDictionary)
        {
            ret &&= environment(owner) &&
                environmentDictionary->isEnvironmentOfType(environment(owner),
                    specificationData["limited by"]["environment"]);
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("You are not in the correct environment (%s) to do that.\n",
                specificationData["limited by"]["environment"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkEnvironmentStateLimitor(mapping specificationData, 
    object owner, int verbose, string colorConfiguration, 
    object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "environment state"))
    {
        object environment = environment(owner);
        if (environment)
        {
            if (!pointerp(specificationData["limited by"]["environment state"]))
            {
                specificationData["limited by"]["environment state"] =
                    ({ specificationData["limited by"]["environment state"] });
            }

            ret &&= (member(specificationData["limited by"]["environment state"],
                environment->currentState()) > -1);
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                format(sprintf("You are not in the correct environment state "
                "(%s) to do that.\n",
                pointerp(specificationData["limited by"]["environment state"]) ?
                    implode(specificationData["limited by"]["environment state"], ", ") :
                    specificationData["limited by"]["environment state"]), 78),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkTimeOfDayLimitor(mapping specificationData, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "time of day"))
    {
        object environmentDictionary = getDictionary("environment");
        if (environmentDictionary)
        {
            if (pointerp(specificationData["limited by"]["time of day"]))
            {
                ret &&= (member(specificationData["limited by"]["time of day"],
                    environmentDictionary->timeOfDay()) > -1);
            }
            else
            {
                ret &&= (environmentDictionary->timeOfDay() ==
                    specificationData["limited by"]["time of day"]);
            }
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("It is not the proper time of day (%s) to do that.\n",
                    pointerp(specificationData["limited by"]["time of day"]) ?
                        implode(specificationData["limited by"]["time of day"], ", ") :
                        specificationData["limited by"]["time of day"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkSeasonLimitor(mapping specificationData, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "season"))
    {
        object environmentDictionary = getDictionary("environment");
        if (environmentDictionary)
        {
            if (pointerp(specificationData["limited by"]["season"]))
            {
                ret &&= (member(specificationData["limited by"]["season"],
                    environmentDictionary->season()) > -1);
            }
            else
            {
                ret &&= (environmentDictionary->season() ==
                    specificationData["limited by"]["season"]);
            }
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("It is not the proper season (%s) to do that.\n",
                    pointerp(specificationData["limited by"]["season"]) ?
                        implode(specificationData["limited by"]["season"], ", ") :
                        specificationData["limited by"]["season"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int checkMoonPhaseLimitor(mapping specificationData, 
    int verbose, string colorConfiguration, object configuration)
{
    int ret = 1;

    if (member(specificationData["limited by"], "moon phase"))
    {
        object environmentDictionary = getDictionary("environment");
        if (environmentDictionary)
        {
            if (pointerp(specificationData["limited by"]["moon phase"]))
            {
                ret &&= (member(specificationData["limited by"]["moon phase"],
                    environmentDictionary->moonPhase()) > -1);
            }
            else
            {
                ret &&= (environmentDictionary->moonPhase() ==
                    specificationData["limited by"]["moon phase"]);
            }
        }
        if (!ret && verbose)
        {
            write(configuration->decorate(
                sprintf("It is not the proper moon phase (%s) to do that.\n",
                    pointerp(specificationData["limited by"]["moon phase"]) ?
                        implode(specificationData["limited by"]["moon phase"], ", ") :
                        specificationData["limited by"]["moon phase"]),
                "missing prerequisites", "research", colorConfiguration));
        }
    }
    return ret;
}
