//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public void onRegisterItem()
{
    // The test needs to catch these exceptions. It was the most elegant way I
    // could derive to test events.
    raise_error("event handler: onRegisterItem called");
}

/////////////////////////////////////////////////////////////////////////////
public void onUnregisterItem()
{
    raise_error("event handler: onUnregisterItem called");
}

/////////////////////////////////////////////////////////////////////////////
public void onDeath()
{
    raise_error("event handler: onDeath called");
}

/////////////////////////////////////////////////////////////////////////////
public void onHeartBeat()
{
    raise_error("event handler: onHeartBeat called");
}

/////////////////////////////////////////////////////////////////////////////
public void onAttack()
{
    raise_error("event handler: onAttack called");
}

/////////////////////////////////////////////////////////////////////////////
public void onAttacked()
{
    raise_error("event handler: onAttacked called");
}

/////////////////////////////////////////////////////////////////////////////
public void onMove()
{
    raise_error("event handler: onMove called");
}

/////////////////////////////////////////////////////////////////////////////
public void onUsedAbility()
{
    raise_error("event handler: onUsedAbility called");
}

/////////////////////////////////////////////////////////////////////////////
public void onHitPointsChanged()
{
    raise_error("event handler: onHitPointsChanged called");
}

/////////////////////////////////////////////////////////////////////////////
public void onSpellPointsChanged()
{
    raise_error("event handler: onSpellPointsChanged called");
}

/////////////////////////////////////////////////////////////////////////////
public void onStaminaPointsChanged()
{
    raise_error("event handler: onStaminaPointsChanged called");
}

/////////////////////////////////////////////////////////////////////////////
public void onRunAway()
{
    raise_error("event handler: onRunAway called");
}

/////////////////////////////////////////////////////////////////////////////
public void onEquip()
{
    raise_error("event handler: onEquip called");
}

/////////////////////////////////////////////////////////////////////////////
public void onUnequip()
{
    raise_error("event handler: onUnequip called");
}

/////////////////////////////////////////////////////////////////////////////
public void onAdvancedLevel()
{
    raise_error("event handler: onAdvancedLevel called");
}

/////////////////////////////////////////////////////////////////////////////
public void onAdvancedRank()
{
    raise_error("event handler: onAdvancedRank called");
}

/////////////////////////////////////////////////////////////////////////////
public void onDemotedRank()
{
    raise_error("event handler: onDemotedRank called");
}

/////////////////////////////////////////////////////////////////////////////
public void onJoinGuild()
{
    raise_error("event handler: onJoinGuild called");
}

/////////////////////////////////////////////////////////////////////////////
public void onLeaveGuild()
{
    raise_error("event handler: onLeaveGuild called");
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchPointsAdded()
{
    raise_error("event handler: onResearchPointsAdded called");
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchStarted()
{
    raise_error("event handler: onResearchStarted called");
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchCompleted()
{
    raise_error("event handler: onResearchCompleted called");
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchTreeOpen()
{
    raise_error("event handler: onResearchTreeOpen called");
}

/////////////////////////////////////////////////////////////////////////////
public void onCombatDelayed()
{
    raise_error("event handler: onCombatDelayed called");
}

/////////////////////////////////////////////////////////////////////////////
public void onHit(object caller, mapping data)
{
    raise_error(sprintf("event handler: onHit called, data: %s %d, caller: %s", 
        data["type"], data["damage"], program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onTraitAdded()
{
    raise_error("event handler: onTraitAdded called");
}

/////////////////////////////////////////////////////////////////////////////
public void onTraitRemoved()
{
    raise_error("event handler: onTraitRemoved called");
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestStarted(object caller, string data)
{
    raise_error(sprintf("event handler: onQuestStarted called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestAdvancedState(object caller, string data)
{
    raise_error(sprintf("event handler: onQuestAdvancedState called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestCompleted(object caller, string data)
{
    raise_error(sprintf("event handler: onQuestCompleted called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestSucceeded(object caller, string data)
{
    raise_error(sprintf("event handler: onQuestSucceeded called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestFailed(object caller, string data)
{
    raise_error(sprintf("event handler: onQuestFailed called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestActivated(object caller, string data)
{
    raise_error(sprintf("event handler: onQuestActivated called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onQuestDeactivated(object caller, string *data)
{
    raise_error(sprintf("event handler: onQuestDeactivated called: quest -> %s, state -> %s", data[0], data[1]));
}

/////////////////////////////////////////////////////////////////////////////
public void onSkillAdvanced(object caller, string data)
{
    raise_error(sprintf("event handler: onSkillAdvanced called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onSkillDecreased(object caller, string data)
{
    raise_error(sprintf("event handler: onSkillDecreased called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onSkillPointsIncreased(object caller, string data)
{
    raise_error(sprintf("event handler: onSkillPointsIncreased called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onSkillPointsUsed(object caller, string data)
{
    raise_error(sprintf("event handler: onSkillPointsUsed called, data: %s, caller: %s",
        data, program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void customEventHandler(object caller, string data)
{
    raise_error(sprintf("event handler: customEventHandler called: %s", data));
}

/////////////////////////////////////////////////////////////////////////////
public void onIntoxicationChanged(object caller)
{
    raise_error(sprintf("event handler: onIntoxicationChanged called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onStuffedChanged(object caller)
{
    raise_error(sprintf("event handler: onStuffedChanged called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onDruggedChanged(object caller)
{
    raise_error(sprintf("event handler: onDruggedChanged called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onSoakedChanged(object caller)
{
    raise_error(sprintf("event handler: onSoakedChanged called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onDrunk(object caller)
{
    raise_error(sprintf("event handler: onDrunk called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onSober(object caller)
{
    raise_error(sprintf("event handler: onSober called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onDetoxified(object caller)
{
    raise_error(sprintf("event handler: onDetoxified called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onWastedOnDrugs(object caller)
{
    raise_error(sprintf("event handler: onWastedOnDrugs called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onNoLongerDrugged(object caller)
{
    raise_error(sprintf("event handler: onNoLongerDrugged called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onSoaked(object caller)
{
    raise_error(sprintf("event handler: onSoaked called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onNoLongerSoaked(object caller)
{
    raise_error(sprintf("event handler: onNoLongerSoaked called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onCannotEatMore(object caller)
{
    raise_error(sprintf("event handler: onCannotEatMore called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onHungry(object caller)
{
    raise_error(sprintf("event handler: onHungry called, caller: %s",
        program_name(caller)));
}

/////////////////////////////////////////////////////////////////////////////
public void onBeginDetox(object caller)
{
    raise_error(sprintf("event handler: onBeginDetox called, caller: %s",
        program_name(caller)));
}
