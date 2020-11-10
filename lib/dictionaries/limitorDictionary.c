//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/dictionaries/limitors/validators.c";
virtual inherit "/lib/dictionaries/limitors/user-checkers.c";
virtual inherit "/lib/dictionaries/limitors/environment-checkers.c";

/////////////////////////////////////////////////////////////////////////////
public nomask int userFactorsMet(mapping specificationData, object owner, 
    object target, int verbose)
{
    int ret = 1;

    if (member(specificationData, "limited by") && owner && objectp(owner))
    {
        string colorConfiguration = owner->colorConfiguration();
        object configuration = getDictionary("configuration");

        // This slice of yuck allows all of the limitors to
        // display failure messages rather than only the first
        // that evaluates to false if they were all AND-ed together
        ret = checkOpponentRaceLimitor(specificationData, target, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkOpponentGuildLimitor(specificationData, target, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkOpponentFactionLimitor(specificationData, target, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkCraftingTypeLimitor(specificationData, target, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkIntoxicatedLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkDruggedLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkNearDeathLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkStaminaDrainedLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkSpellPointsDrainedLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkEquipmentLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkSkillLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkAttributeLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkRaceLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkGuildLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkFactionLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkQuestLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkResearchLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkTraitLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkResearchActiveLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs int environmentalFactorsMet(
    mapping specificationData, object owner, int verbose)
{
    int ret = 1;

    if (member(specificationData, "limited by") && owner && objectp(owner))
    {
        string colorConfiguration = owner->colorConfiguration();
        object configuration = getDictionary("configuration");

        ret = checkEnvironmentLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkEnvironmentStateLimitor(specificationData, owner, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkTimeOfDayLimitor(specificationData, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkSeasonLimitor(specificationData, verbose,
            colorConfiguration, configuration) && ret;

        ret = checkMoonPhaseLimitor(specificationData, verbose,
            colorConfiguration, configuration) && ret;
    }
    return ret;
}
