//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"


func kilocalories(fats: Double, proteins: Double, carbohydrates: Double) -> Double{
    return 4 * (carbohydrates + proteins) + 9 * fats
}

print(kilocalories(fats: 70, proteins: 10, carbohydrates: 10))