/*
  ==============================================================================

    Constante.cpp
    Created: 19 Apr 2025 9:46:49am
    Author:  olivier

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ConstanteComponent.h"
#include "PluginEditor.h"

//==============================================================================
ConstanteComponent::ConstanteComponent()
{
    setSize(50, 50);
    borderColour = juce::Colours::green;

}

ConstanteComponent::~ConstanteComponent()
{
 
}

void ConstanteComponent::paint (juce::Graphics& g)
{
    // Dessiner le fond
    g.fillAll(juce::Colours::green);

    // Dessiner le texte
    g.setColour(juce::Colours::white);
    g.drawText("Const", getLocalBounds(), juce::Justification::centred);

    // Appeler la méthode de la classe de base pour dessiner la bordure
    ComponentPerso::paint(g);
}

void ConstanteComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


void ConstanteComponent::setSelected(bool selected)
{
    isSelected = selected;
    repaint(); // Redessiner pour mettre à jour la bordure
}