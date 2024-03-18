#pragma once

#define LOG(Format, ...) UE_LOG(LogTemp, Warning, TEXT(Format), ##__VA_ARGS__)
#define LOG_SCREEN(Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.f, FColor::Cyan, FString::Printf(TEXT(Format), ##__VA_ARGS__))