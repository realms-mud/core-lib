// File: lib/modules/domains/trading/taipanStateMachine.c

inherit "/lib/core/stateMachine.c";

/////////////////////////////////////////////////////////////////////////////
public void SetupTaipanStates()
{
    addState("at port", "You are docked at a port and may trade, bank, or travel.");
    addEntryAction("at port", "showTradingMenu");

    addState("traveling", "You are traveling to another port.");
    addEntryAction("traveling", "startTravel");
    addTransition("at port", "traveling", "departPort");
    addTransition("traveling", "at port", "arrivePort");

    addState("random event", "A random event is occurring.");
    addEntryAction("random event", "handleRandomEvent");
    addTransition("traveling", "random event", "triggerEvent");

    addState("battle", "You are engaged in a battle!");
    addEntryAction("battle", "startSeaBattle");
    addTransition("random event", "battle", "startBattle");
    addTransition("battle", "traveling", "endBattle");

    addState("overloaded", "Your vehicle is overloaded!");
    addEntryAction("overloaded", "handleOverload");
    addTransition("at port", "overloaded", "overload");
    addTransition("overloaded", "at port", "resolveOverload");

    addFinalState("bankrupt", "You have gone bankrupt.", 0, "failure");
    addEntryAction("bankrupt", "showBankruptcy");
    addTransition("at port", "bankrupt", "bankrupt");

    addFinalState("dead", "You have died at sea.", 0, "failure");
    addEntryAction("dead", "showDeath");
    addTransition("battle", "dead", "dead");

    setInitialState("at port");

}

/////////////////////////////////////////////////////////////////////////////
// Example entry action for "at port"
public void showTradingMenu()
{
    // Call tradingSelector or similar to present port options
    // e.g., present buy/sell/bank/transfer/retire menu
    // tradingSelector->presentMenu();
}

/////////////////////////////////////////////////////////////////////////////
// Example entry action for "traveling"
public void startTravel()
{
    // Call travelSelector or similar to handle travel logic
    // travelSelector->beginTravel();
}

/////////////////////////////////////////////////////////////////////////////
// Example entry action for "random event"
public void handleRandomEvent()
{
    // TODO: Implement random event logic (pirates, storm, Li Yuen, Wu, etc.)
    // This should trigger the appropriate event (e.g., startBattle, arrivePort, etc.)
}

/////////////////////////////////////////////////////////////////////////////
// Example entry action for "sea battle"
public void startSeaBattle()
{
    // TODO: Implement sea battle logic
    // This should handle combat and, on completion, trigger endBattle or dead
}

/////////////////////////////////////////////////////////////////////////////
// Example entry action for "overloaded"
public void handleOverload()
{
    // Call overloadSelector or similar to resolve overload
    // overloadSelector->presentMenu();
}

/////////////////////////////////////////////////////////////////////////////
// Example entry actions for end states
public void showRetirement()
{
    // TODO: Show retirement/endgame summary
}

public void showBankruptcy()
{
    // TODO: Show bankruptcy/endgame summary
}

public void showDeath()
{
    // TODO: Show death/endgame summary
}
