package com.opentext.apps.cfc.common.filter.XSSFilter;

import net.sf.ehcache.search.parser.MCriteria;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletRequestWrapper;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Pattern;

import org.apache.commons.text.StringEscapeUtils;
// intended for preventing XSS attacking
public class XSSRequestWrapper extends HttpServletRequestWrapper {
    private Map<String, String[]> escapedParameterValuesMap = new HashMap<String, String[]>();

    public XSSRequestWrapper(HttpServletRequest req){
        super(req);
    }

    @Override
    public String getParameter(String name){
        String[] escapedParameterValues = escapedParameterValuesMap.get(name);
        String escapedParameterValue = null;
        if (escapedParameterValues != null){
            escapedParameterValue = escapedParameterValues[0];
        }else{
            String parameterValue = super.getParameter(name);

            //  HTML transformation characters
            escapedParameterValue = org.springframework.web.util.HtmlUtils.htmlEscape(parameterValue);

            // SQL injection characters
//            escapedParameterValue = StringEscapeUtils.escapeSql(escapedParameterValue);

            escapedParameterValuesMap.put(name, new String[]{escapedParameterValue});
        }
        return escapedParameterValue;
    }
    @Override
    public String[] getParameterValues(String name){
        String[] escapedParameterValues = escapedParameterValuesMap.get(name);
        if (escapedParameterValues==null){
            String[] parametersValues = super.getParameterValues(name);
            escapedParameterValues = new String[parametersValues.length];

            for (int i=0;i<parametersValues.length;i++){
                String parameterValue = parametersValues[i];
                String escapedParameterValue = parameterValue;

                escapedParameterValue = org.springframework.web.util.HtmlUtils.htmlEscape(parameterValue);

//                escapedParameterValue = StringEscapeUtils.escapeSql(escapedParameterValue);
                escapedParameterValues[i] = escapedParameterValue;
            }

            escapedParameterValuesMap.put(name, escapedParameterValues);
        }

        return escapedParameterValues;
    }
}
