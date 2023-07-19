#include<bits/stdc++.h>
using namespace std;


/*
REST API : Maximum Transfer

Use the HTTP GET method to give information from a database paatient medical records.
Query 'https://jsonmock.hackerrank.com/api/transactions' to find all the records. The 
query result is paginated and can be further accessed by appending '?page=num' where 
num is the page number.

The query response from the API is a JSON with the following fields:
    . page : the current page
    . per_page : maximum number of results per page
    . total : the total number of results
    . total_pages : the total number of pages to query to get all results
    . data : an array of JSON objects that contains transaction records

The data field in the response contains a list of transaction records with the following schema:
    . id : the unique ID of the transaction
    . userid : the id of the patient
    . userName : the name of the patient 
    . tiemStamp 
    . txnType : either 'credit' or 'debit'
    . amount : a float as a string in currency format { '$123,456' }
    . location : object, the location of the user 
        . id : the unique ID of the location
        . address
        . city 
        . zipCode 
    .ip : IP of the user

Given a userName and city: filter records by the given keywords. Find the maximum amount credited and 
the maximum amount debited for the given user and the city. Return an array of strings where the first
element is the credit amount and the second element is the debit amount. These are floats converted
to strings in currency format, just as they are in the JSON data.

*/



vector<string> maximumTransfer(string name, string city){

}


int main(){

}